// https://nanti.jisuanke.com/t/31720
#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef long long ll;
const int mod=1e9+7;
ll dp[10005];
int cost[405];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n,q,v,c;scanf("%d%d",&n,&q);
        int cnt=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&v,&c);
            for(int i=0;i<c;i++)
                cost[cnt++]=v,v+=v;
        }
        memset(dp,0,sizeof dp);dp[0]=1;
        for(int i=1;i<cnt;i++)
            for(int j=10000;j>=cost[i];j--)
                dp[j]=(dp[j]+dp[j-cost[i]])%mod;
        while(q--){
            scanf("%d",&c);
            printf("%lld\n",dp[c]);
        }
    }
    return 0;
}