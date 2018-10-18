#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=365;
struct edge{
    int dest;
    edge*next;
}e[maxn*maxn*2],*head[maxn];
std::deque<int>q;
bool inque[maxn],inblossom[maxn],inpath[maxn];
int match[maxn],pre[maxn],base[maxn],cnt,nodenum;
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
int findroot(int u,int v){
    memset(inpath,false,sizeof inpath);
    while(true){
        u=base[u];
        inpath[u]=true;
        if(!~match[u])break;
        u=pre[match[u]];
    }
    while(true){
        v=base[v];
        if(inpath[v])return v;
        v=pre[match[v]];
    }
}
void reset(int u,int rt){
    while(u!=rt){
        int v=match[u];
        inblossom[base[u]]=true;
        inblossom[base[v]]=true;
        v=pre[v];
        if(base[v]!=rt)
            pre[v]=match[u];
        u=v;
    }
}
void contract(int u,int v){
    int rt=findroot(u,v);
    memset(inblossom,false,sizeof inblossom);
    reset(u,rt);reset(v,rt);
    if(base[u]!=rt)pre[u]=v;
    if(base[v]!=rt)pre[v]=u;
    for(int i=1;i<=nodenum;i++){
        if(inblossom[base[i]]){
            base[i]=rt;
            if(!inque[i]){
                q.push_back(i);
                inque[i]=true;
            }
        }
    }
}
bool dfs(int src){
    memset(pre,-1,nodenum+1<<2);
    memset(inque,false,nodenum+1);
    for(int i=0;i<=nodenum;i++)base[i]=i;
    q.clear();q.push_back(src);inque[src]=true;
    while(q.size()){
        int u=q.front();q.pop_front();
        for(edge*i=head[u];i;i=i->next){
            int v=i->dest;
            if(!(base[v]!=base[u]&&match[u]!=v))continue;
            if(v==src||(~match[v]&&~pre[match[v]])){
                contract(u,v);continue;
            }if(~pre[v])continue;pre[v]=u;
            if(~match[v]){
                q.push_back(match[v]);
                inque[match[v]]=true;
            }else{
                u=v;int w;
                while(u!=-1){
                    v=pre[u];
                    w=match[v];
                    match[u]=v;
                    match[v]=u;
                    u=w;
                }return true;
            }
        }
    }return false;
}
int x[maxn],y[maxn];
inline int abs(int x){return x<0?-x:x;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%d",&nodenum)){
        for(int i=1;i<=nodenum;i++)
            scanf("%d%d",x+i,y+i);
        int L;scanf("%d",&L);
        memset(head,cnt=0,sizeof head);
        for(int i=1;i<nodenum;i++)
            for(int j=i+1;j<=nodenum;j++)
                if(L>=abs(x[i]-x[j])+abs(y[i]-y[j]))
                    addedge(i,j),addedge(j,i);
        memset(match,-1,sizeof match);
        for(int i=1;i<=nodenum;i++)
            if(!~match[i])dfs(i);
        for(int i=1;i<=nodenum;i++)
            if(!~match[i])goto NO;
        puts("YES");continue;NO:puts("NO");
    }
    return 0;
}