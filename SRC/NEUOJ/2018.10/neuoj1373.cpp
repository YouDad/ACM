#include<stdio.h>
#include<string.h>
const int mod=1e9+7;
int a[1005],dp[2][11][1024];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n,d;scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        memset(dp,0,sizeof dp);dp[0][0][0]=1;
        for(int i=1;i<=n;i++){
            memset(dp[i%2],0,sizeof dp[i%2]);
            for(int j=0;j<=d;j++)for(int k=0;k<1024;k++)
                (dp[i%2][j][k^a[i]]+=dp[1-i%2][j][k])%=mod,
                (dp[i%2][j][k]+=dp[1-i%2][j-1][k]*(j>0))%=mod;
        }long long ans=0;
        for(int i=0;i<=d;i++)ans+=dp[n%2][i][0];
        printf("%d\n",ans%mod);
    }
    return 0;
}