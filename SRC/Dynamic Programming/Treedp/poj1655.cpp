#include<stdio.h>
#include<string.h>
const int maxn=20005;
struct edge{
    int dest;
    edge*next;
}e[maxn*2],*head[maxn];
int cnt;
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
int dp[maxn],pre[maxn];//nodenum
void dfs(int u){
    dp[u]=1;
    for(edge*i=head[u];i;i=i->next){
        int v=i->dest;if(pre[v])continue;
        pre[v]=u;dfs(v);dp[u]+=dp[v];
    }
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        memset(head,cnt=0,sizeof head);
        memset(pre,0,sizeof pre);
        int n;scanf("%d",&n);
        for(int i=1,u,v;i<n;i++)
            scanf("%d%d",&u,&v),
            addedge(u,v),addedge(v,u);
        pre[1]=1;dfs(1);
        int minbalance=0x3f3f3f3f,minid,sum,max;
        for(int u=1;u<=n;u++){
            sum=0,max=0;
            for(edge*i=head[u];i;i=i->next){
                int v=i->dest;
                if(v==pre[u])continue;
                sum+=dp[v];
                if(max<dp[v])
                    max=dp[v];
            }
            if(dp[1]-sum-1>max)max=dp[1]-sum-1;
            if(max==minbalance&&minid>u)minid=u;
            if(minbalance>max)minbalance=max,minid=u;
        }
        printf("%d %d\n",minid,minbalance);
    }
    return 0;
}