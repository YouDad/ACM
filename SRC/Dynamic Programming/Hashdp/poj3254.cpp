#include<stdio.h>
#include<string.h>
int map[12],state[400],cnt;
long long dp[12][400];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m,t;
    while(~scanf("%d%d",&n,&m)){
        memset(map,0,sizeof map);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&t),map[i]=map[i]*2+1-t;
        for(int i=cnt=0;i<1<<m;i++)
            if(!(i&i<<1))
                state[cnt++]=i;
        memset(dp,0,sizeof dp);
        for(int i=0;i<cnt;i++)
            dp[0][i]=!(state[i]&map[0]);
        for(int i=1;i<n;i++)
            for(int j=0;j<cnt;j++)
                if(!(state[j]&map[i]))
                    for(int k=0;k<cnt;k++)
                        if(!(state[j]&state[k]))
                            dp[i][j]+=dp[i-1][k];
        long long sum=0;
        for(int i=0;i<cnt;i++)
            sum+=dp[n-1][i];
        printf("%lld\n",sum%100000000);
    }
    return 0;
}