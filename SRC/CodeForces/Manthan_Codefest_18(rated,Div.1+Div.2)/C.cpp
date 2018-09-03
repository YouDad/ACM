#include<stdio.h>
char a[1000005],b[1000005];
int dp[1000005];
int min(int a,int b){return a<b?a:b;}
int main(){
    int n;scanf("%d%*c",&n);
    gets(a);gets(b);
    dp[1]=a[0]!=b[0];
    for(int i=2;i<=n;i++){
        if((a[i-2]^b[i-2]&&a[i-1]^b[i-1])&&a[i-1]!=a[i-2])
			dp[i]=min(dp[i-1]+(a[i-1]!=b[i-1]),dp[i-2]+1);
        else
            dp[i]=dp[i-1]+(a[i-1]!=b[i-1]);
    }printf("%d\n",dp[n]);
    return 0;
}