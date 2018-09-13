#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=3005,inf=0x3f3f3f3f;
struct edge{
    int dest;
    edge*next;
}e[maxn*maxn],*head[maxn];
int cnt,nx,ny;
int mx[maxn],my[maxn];
int dx[maxn],dy[maxn],dist;
bool vis[maxn];
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
bool aug(){
    std::queue<int>q;
    dist=inf;
    memset(dx,-1,sizeof dx);
    memset(dy,-1,sizeof dy);
    for(int i=0;i<nx;i++)
        if(mx[i]==-1)
            q.push(i),dx[i]=0;
    while(q.size()){
        int u=q.front();q.pop();
        if(dx[u]>dist)break;
        for(edge*i=head[u];i;i=i->next){
            int v=i->dest;
            if(~dy[v])continue;
            dy[v]=dx[u]+1;
            if(~my[v]){
                dx[my[v]]=dy[v]+1;
                q.push(my[v]);
            }else dist=dy[v];
        }
    }
    return dist!=inf;
}
bool dfs(int u){
    for(edge*i=head[u];i;i=i->next){
        int v=i->dest;
        if(!vis[v]&&dy[v]==dx[u]+1){
            vis[v]=true;
            if(~my[v]&&dy[v]==dist)
                continue;
            if(my[v]==-1||dfs(my[v])){
                my[v]=u;
                mx[u]=v;
                return true;
            }
        }
    }
    return false;
}
int hk(){
    int ret=0;
    memset(mx,-1,sizeof mx);
    memset(my,-1,sizeof my);
    while(aug()){
        memset(vis,false,sizeof vis);
        for(int i=0;i<nx;i++)
            if(!~mx[i]&&dfs(i))
                ret++;
    }
    return ret;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        memset(head,cnt=0,sizeof head);
        int m,u,v;scanf("%d%d",&nx,&m);
        while(m--){
            scanf("%d%d",&u,&v);
            addedge(u-1,v-1);
        }
        printf("%d\n",nx-hk());
    }
    return 0;
}