#include<stdio.h>
const int maxn=130;
double p[maxn][maxn],dp[maxn][maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m;
    while(~scanf("%d",&n)&&~n){
        m=1<<n;
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                scanf("%lf",p[i]+j);
        for(int i=0;i<m;i++)
            dp[0][i]=1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<m;j++)
                dp[i][j]=0;
        for(int k=0;k<n;k++)
            for(int i=0;i<m;i++)
                for(int j=0;j<m;j++)
                    if((i>>k^j>>k)==1)
                        dp[k+1][i]+=dp[k][i]*dp[k][j]*p[i][j];
        double max=-1;int maxi;
        for(int i=0;i<m;i++)
            if(dp[n][i]>max)
                max=dp[n][i],maxi=i;
        printf("%d\n",maxi+1);
    }
    return 0;
}