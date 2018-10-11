#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<stdio.h>
#include<vector>
const int maxn=200005;
using namespace std;
int c[maxn],deep[maxn],pre[maxn][20];
vector<int>G[maxn];
#define dist(u,v) (deep[u]+deep[v]-2*deep[lca(u,v)])
#define foreach(it,obj) for(auto it=obj.begin();it!=obj.end();it++)
int lca(int u,int v){
    if(deep[u]<deep[v])u^=v^=u^=v;
    int d=deep[u]-deep[v];
    for(int i=0;d;i++,d/=2)if(d&1)u=pre[u][i];
    if(u==v)return u;
    for(int i=19;~i;i--)
        if(pre[u][i]^pre[v][i])
            u=pre[u][i],v=pre[v][i];
    return pre[u][0];
}
void dfs(int u,int f){
    pre[u][0]=f,deep[u]=deep[f]+1;
    for(int i=1;pre[u][i-1];i++)
        pre[u][i]=pre[pre[u][i-1]][i-1];
    foreach(it,G[u])if(*it!=f)dfs(*it,u);
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    for(int i=1,u,v;i<n;i++)
        scanf("%d%d",&u,&v),
        G[u].push_back(v),
        G[v].push_back(u);
    dfs(1,0);long long ans=0;
    for(int i=1;i<=n/2;i++)
        for(int j=2;i*j<=n;j++)
            ans+=dist(i,i*j)+1;
    printf("%lld\n",ans);
    return 0;
}