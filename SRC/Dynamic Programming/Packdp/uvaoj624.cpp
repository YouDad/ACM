#include<stdio.h>
#include<string.h>
int c[25],dp[1500];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int m,n;
    while(~scanf("%d%d",&m,&n)){
        for(int i=0;i<n;i++)
            scanf("%d",c+i);
        memset(dp,-1,sizeof dp);dp[0]=0;
        for(int i=0;i<n;i++)
            for(int j=m;j>=c[i];j--)
                if(~dp[j-c[i]]&&!~dp[j])
                    dp[j]=c[i];
        while(!~dp[m])m--;
        int sum=0;
        while(m){
            printf("%d ",dp[m]);
            sum+=dp[m];
            m-=dp[m];
        }
        printf("sum:%d\n",sum);
    }
    return 0;
}