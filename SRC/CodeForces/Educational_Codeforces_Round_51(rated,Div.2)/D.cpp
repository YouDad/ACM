#include<stdio.h>
const int mod=998244353;
long long dp[2][2005][4];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,k;scanf("%d%d",&n,&k);
    dp[1][1][0]=dp[1][1][3]=dp[1][2][1]=dp[1][2][2]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i%2][j][0]=(dp[1-i%2][j][0]+dp[1-i%2][j][1]+dp[1-i%2][j][2]+dp[1-i%2][j-1][3])%mod;
            dp[i%2][j][1]=(dp[1-i%2][j-1][0]+dp[1-i%2][j][1]+(j<2?0:dp[1-i%2][j-2][2])+dp[1-i%2][j-1][3])%mod;
            dp[i%2][j][2]=(dp[1-i%2][j-1][0]+(j<2?0:dp[1-i%2][j-2][1])+dp[1-i%2][j][2]+dp[1-i%2][j-1][3])%mod;
            dp[i%2][j][3]=(dp[1-i%2][j-1][0]+dp[1-i%2][j][1]+dp[1-i%2][j][2]+dp[1-i%2][j][3])%mod;
        }
    }
    printf("%I64d\n",(dp[n%2][k][0]+dp[n%2][k][1]+dp[n%2][k][2]+dp[n%2][k][3])%mod);
    return 0;
}