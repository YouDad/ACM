#include<stdio.h>
#include<string.h>
const int maxn=50005;
struct edge{
    int dest,dist;
    struct edge*next;
}e[maxn*2],*head[maxn];
int cnt;
void addedge(int u,int v,int w){
    e[cnt].dest=v;
    e[cnt].dist=w;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
int pre[maxn][20],deep[maxn];
long long dist[maxn];
void dfs(int u,int f,int w){
    pre[u][0]=f;
    deep[u]=deep[f]+1;
    dist[u]=dist[f]+w;
    for(int i=0;pre[u][i];i++)
        pre[u][i+1]=pre[pre[u][i]][i];
    for(edge*i=head[u];i;i=i->next)
        if(i->dest!=f)
            dfs(i->dest,u,i->dist);
}
int lca(int u,int v){
    if(deep[u]<deep[v])u^=v^=u^=v;
    int delta=deep[u]-deep[v];
    for(int i=0;delta;i++,delta/=2)
        if(delta&1)
            u=pre[u][i];
    if(u==v)
        return u;
    for(int i=19;~i;i--)
        if(pre[u][i]^pre[v][i])
            u=pre[u][i],v=pre[v][i];
    return pre[u][0];
}
#define dis(x,y) (dist[x]+dist[y]-2*dist[lca(x,y)])
long long max(long long a,long long b){return a>b?a:b;}
int main(){
#ifdef LOCAL_DEBUG
	freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m;scanf("%d%d",&n,&m);
    memset(head,cnt=0,sizeof head);
    long long sum=0;
    for(int u,v,w,i=1;i<n;i++){
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
        sum+=2*w;
    }
    dfs(1,0,0);
    long long maxdist=0;
    for(int i=1;i<=n;i++)
        maxdist=max(maxdist,dis(m,i));
    printf("%lld\n",sum-maxdist);
    return 0;
}