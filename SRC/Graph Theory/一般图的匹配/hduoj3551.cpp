#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=805;
struct edge{
    int dest;
    edge*next;
}e[maxn*maxn*2],*head[maxn];
std::deque<int>q;
int pre[maxn],cnt;
int vis[maxn],nxt[maxn],match[maxn];
char mrk[maxn];
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    e[cnt].dest=u;
    e[cnt].next=head[v];
    head[v]=e+cnt++;
}
int find(int x){return x==pre[x]?x:pre[x]=find(pre[x]);}
void join(int x,int y){x=find(x);y=find(y);if(x!=y)pre[x]=y;}
int root(int u,int v){
    static int cnt=0;cnt++;u^=v^=u^=v;
    while(true){u^=v^=u^=v;
        if(!~u)continue;u=find(u);
        if(vis[u]==cnt)return u;vis[u]=cnt;
        u=~match[u]?nxt[match[u]]:-1;
    }
}
bool aug(int src){
    memset(mrk,0,sizeof mrk);
    memset(nxt,-1,sizeof nxt);
    memset(vis,-1,sizeof vis);
    for(int i=0;i<maxn;++i)pre[i]=i;
    q.clear();q.push_back(src);mrk[src]=1;
    while(q.size()){
        int u=q.front();q.pop_front();
        for(edge*i=head[u];i;i=i->next){
            int v=i->dest;if(find(u)==find(v))continue;
            if(match[u]==v||mrk[v]==2)continue;
            if(mrk[v]==1){
                int rt=root(u,v);
                if(find(u)!=rt)nxt[u]=v;
                if(find(v)!=rt)nxt[v]=u;
                for(int i=0;i<2;i++)
                for(int a=i?u:v;a!=rt;){
                    int b=match[a],c=nxt[b];
                    if(find(c)!=rt)nxt[c]=b;
                    if(mrk[b]==2)q.push_back(b),mrk[b]=1;
                    if(mrk[c]==2)q.push_back(c),mrk[c]=1;
                    join(a,b);join(b,c);a=c;
                }continue;
            }nxt[v]=u;
            if(~match[v]){
                q.push_back(match[v]);
                mrk[match[v]]=1;mrk[v]=2;
            }else{
                int tmp;
                for(u=v;~u;u=tmp){
                    v=nxt[u];tmp=match[v];
                    match[v]=u;match[u]=v;
                }return true;
            }
        }
    }return false;
}
int u[maxn],v[maxn],deg[maxn],d[maxn];
int id[maxn],num[maxn];
inline int abs(int x){return x<0?-x:x;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        printf("Case %d: ",kase);
        int n,m;scanf("%d%d",&n,&m);
        memset(deg,0,sizeof deg);
        for(int i=0;i<m;i++){
            scanf("%d%d",u+i,v+i);
            deg[u[i]]++;deg[v[i]]++;
        }
        for(int i=1;i<=n;i++)
            scanf("%d",d+i);
        int c=0;
        for(int i=1;i<=n;i++){
            if(d[i]-deg[i]>0)goto No;
            id[i]=c;c+=num[i]=deg[i]-d[i];
        }
        memset(head,cnt=0,sizeof head);
        for(int i=0;i<m;i++,c+=2){
            addedge(c,c+1);
            int U=id[u[i]],V=id[v[i]];
            for(int j=0;j<num[u[i]];j++)
                addedge(c,U+j);
            for(int j=0;j<num[v[i]];j++)
                addedge(V+j,c+1);
        }
        memset(match,-1,sizeof match);
        for(int i=0;i<c;i++)
            if(!~match[i]&&!aug(i))
                goto No;
        puts("YES");continue;
        No:puts("NO");
    }
    return 0;
}