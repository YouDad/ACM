#include<stdio.h>
const int maxn=105;
int a[maxn],dp[maxn][maxn];
inline void selmin(int&a,int b){if(a>b)a=b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)dp[i][i]=1;
        for(int i=n-2;~i;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++)
                    if(a[i]==a[k])
                        selmin(dp[i][j],dp[i+1][k-1]+dp[k][j]);
            }
        }
        printf("Case %d: %d\n",kase,dp[0][n-1]);
    }
    return 0;
}