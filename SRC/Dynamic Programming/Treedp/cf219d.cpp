#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
const int maxn=200005;
struct edge{
    int dest;
    bool inv;
    edge*next;
}e[maxn*2],*head[maxn];
int cnt,dp[maxn];
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    e[cnt].inv=false;
    head[u]=e+cnt++;
    e[cnt].dest=u;
    e[cnt].next=head[v];
    e[cnt].inv=true;
    head[v]=e+cnt++;
}
bool vis[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    for(int i=1,u,v;i<n;i++)
        scanf("%d%d",&u,&v),
        addedge(u,v);
    std::queue<int>q;
    q.push(1);int sum=0;
    while(q.size()){
        int u=q.front();q.pop();vis[u]=true;
        for(edge*i=head[u];i;i=i->next){
            if(vis[i->dest])continue;
            if(i->inv)sum++;
            dp[i->dest]=dp[u]+(i->inv?-1:1);
            q.push(i->dest);
        }
    }
    std::vector<int>v;
    int min=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
        if(dp[i]==min)
            v.push_back(i);
        else if(dp[i]<min)
            min=dp[i],v.clear(),v.push_back(i);
    printf("%d\n",min+sum);
    for(int i=0;i<v.size();i++)
        printf("%d%c",v[i]," \n"[i==v.size()-1]);
    return 0;
}