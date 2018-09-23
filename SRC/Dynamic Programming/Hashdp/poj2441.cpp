#include<stdio.h>
#include<string.h>
int a[20][21],dp[1<<20];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m,t;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%d",a[i]);
            for(int j=1;j<=a[i][0];j++)
                scanf("%d",&t),a[i][j]=1<<t-1;
        }
        if(n>m){puts("0");continue;}
        memset(dp,0,4<<m);dp[0]=1;
        for(int i=0;i<n;i++)
            for(int u=(1<<m)-1;~u;u--)
                if(dp[u]){
                    for(int j=1;j<=a[i][0];j++)
                        if(!(a[i][j]&u))
                            dp[a[i][j]|u]+=dp[u];
                    dp[u]=0;
                }
        int sum=0;
        for(int i=0;i<1<<m;i++)
            sum+=dp[i];
        printf("%d\n",sum);
    }
    return 0;
}