#include<stdio.h>
#include<string.h>
#include<algorithm>
const int maxn=10005;
struct edge{
    int dest,dist;
    edge*next;
}e[maxn*2],*head[maxn];
int cnt,n,k;
bool vis[maxn];
void addedge(int u,int v,int w){
    e[cnt].dest=v;
    e[cnt].dist=w;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
int sz[maxn],max[maxn];
void dfssz(int u,int f){
    sz[u]=1;max[u]=0;
    for(edge*i=head[u];i;i=i->next){
        if(i->dest==f||vis[i->dest])continue;
        dfssz(i->dest,u);
        sz[u]+=sz[i->dest];
        if(max[u]<sz[i->dest])
            max[u]=sz[i->dest];
    }
}
int min,rt,r;
void dfsrt(int u,int f){
    if(max[u]<sz[r]-sz[u])max[u]=sz[r]-sz[u];
    if(min>max[u])min=max[u],rt=u;
    for(edge*i=head[u];i;i=i->next)
        if(i->dest!=f&&!vis[i->dest])
            dfsrt(i->dest,u);
}
int dis[maxn];
void dfsds(int u,int f,int d){
    if(d>k)return;dis[cnt++]=d;
    for(edge*i=head[u];i;i=i->next)
        if(i->dest!=f&&!vis[i->dest])
            dfsds(i->dest,u,i->dist+d);
}
int calc(int u,int d){
    dfsds(u,cnt=0,d);
    std::sort(dis,dis+cnt);
    int ret=0;
    for(int i=0,j=cnt-1;i<j;i++){
        while(dis[i]+dis[j]>k&&i<j)j--;
        ret+=j-i;
    }return ret;
}
int ans;
void dfs(int u){
    dfssz(u,0);
    min=0x3f3f3f3f;
    r=u;dfsrt(u,0);
    ans+=calc(rt,0);
    vis[rt]=true;
    for(edge*i=head[rt];i;i=i->next)
        if(!vis[i->dest])
            ans-=calc(i->dest,i->dist),dfs(i->dest);
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&k)&&n+k){
        memset(head,cnt=0,sizeof head);
        memset(vis,false,sizeof vis);
        for(int i=1,u,v,w;i<n;i++)
            scanf("%d%d%d",&u,&v,&w),
            addedge(u,v,w),addedge(v,u,w);
        ans=0;dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}