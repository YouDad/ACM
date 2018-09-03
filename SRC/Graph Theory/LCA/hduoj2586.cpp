#include<stdio.h>
#include<string.h>
const int maxn=40005;
struct edge{
    int v,w;
    struct edge*next;
}e[maxn*2],*head[maxn];
int deep[maxn],dist[maxn],cnt;
void addedge(int u,int v,int w){
    e[cnt].v=v;e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    e[cnt].v=u;e[cnt].w=w;
    e[cnt].next=head[v];
    head[v]=e+cnt++;
}
int prev[maxn][20];
void dfs(int u){
    for(edge*i=head[u];i;i=i->next){
        int v=i->v,w=i->w;
        if(!prev[v][0]){
            prev[v][0]=u;
            deep[v]=deep[u]+1;
            dist[v]=dist[u]+w;
            dfs(v);
        }
    }
}
void doubly(int n){
    for(int j=1;1<<j<=n;j++)
        for(int i=1;i<=n;i++)
            prev[i][j]=prev[prev[i][j-1]][j-1];
}
int lca(int a,int b){int c;
    if(deep[a]<deep[b])a^=b^=a^=b;
    for(c=0;1<<c+1<=deep[a];c++);
    for(int j=c;~j;j--)
        if(deep[a]-deep[b]>=1<<j)
            a=prev[a][j];
    if(a==b)return a;
    for(int j=c;~j;j--)
        if(prev[a][j]^prev[b][j])
            a=prev[a][j],b=prev[b][j];
    return prev[a][0];
}
int main(){
    int t;scanf("%d",&t);
    while(t--){cnt=0;
        memset(head,0,sizeof head);
        memset(deep,0,sizeof deep);
        memset(dist,0,sizeof dist);
        memset(prev,0,sizeof prev);
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1,u,v,w;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        prev[1][0]=1;dfs(1);prev[1][0]=0;
        doubly(n);
        for(int u,v;m--;){
            scanf("%d%d",&u,&v);
            int LCA=lca(u,v);
            printf("%d\n",dist[u]+dist[v]-2*dist[LCA]);
        }
    }
    return 0;
}