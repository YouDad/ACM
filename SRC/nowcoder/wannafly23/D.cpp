//https://www.nowcoder.com/acm/contest/161/D
#include<stdio.h>
#include<vector>
#include<map>
#include<utility>
const int maxn=100005;
using namespace std;
typedef pair<int,int> pii;
int n,q,c[maxn],deep[maxn],pre[maxn][20];
vector<int>G[maxn];
map<int,vector<int>>st;
map<int,pii>dp;
#define dist(u,v) deep[u]+deep[v]-2*deep[lca(u,v)]
#define findmax(x,y) if((d=dist(x,y))>dis)dis=d,ret=pii(x,y)
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
pii merge(pii a,pii b){
    if(!a.first)return b;
    pii ret;int dis=-1e9,d;
    findmax(a.first,b.first);
    findmax(a.first,a.second);
    findmax(a.second,b.first);
    findmax(b.first,b.second);
    return ret;
}
int findans(pii a,pii b){
    pii ret;int dis=-1e9,d;
    findmax(a.first,b.first);
    findmax(a.second,b.first);
    findmax(a.first,b.second);
    findmax(a.second,b.second);
    return dis;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",&c[i]),
        st[c[i]].push_back(i);
    for(int i=2,u,v;i<=n;++i)
        scanf("%d%d",&u,&v),
        G[u].push_back(v),
        G[v].push_back(u);
    dfs(1,0);
    foreach(v,st){
        pii ans(0,0);
        foreach(c,v->second)
            ans=merge(ans,pii(*c,*c));
        dp[v->first]=ans;
    }
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        if(dp.count(x)&&dp.count(y))
            printf("%d\n",findans(dp[x],dp[y]));
        else puts("0");
    }
}