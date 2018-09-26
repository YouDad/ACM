#include<stdio.h>
double dp[1005][1005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int w,b;scanf("%d%d",&w,&b);
    for(int i=1;i<=w;i++)dp[i][0]=1;
    for(int j=0;j<=b;j++)dp[0][j]=0;
    for(int i=1;i<=w;i++)for(int j=1;j<=b;j++){
        dp[i][j]=(double)i/(i+j);int mul=j*j-j;
        long long div=(i+j)*(i+j-1LL)*(i+j-2);
        if(j>=2)dp[i][j]+=dp[i-1][j-2]*mul*(i-0)/div;
        if(j>=3)dp[i][j]+=dp[i-0][j-3]*mul*(j-2)/div;
    }printf("%.9lf\n",dp[w][b]);
    return 0;
}