#include<stdio.h>
int dp[10005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,j,t=0;scanf("%d%*c",&n);dp[0]=1;
    for(int i=0;i<n;i++){
        if(getchar()=='(')
            for(t++,j=t;j>=1;j--)dp[j]=(dp[j]+dp[j-1])%2333;
        else
            for(t--,j=0;j<=t;j++)dp[j]=(dp[j]+dp[j+1])%2333;
        dp[t+1]=0;
    }
    printf("%d\n",dp[0]);
    return 0;
}