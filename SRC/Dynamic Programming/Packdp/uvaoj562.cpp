#include<stdio.h>
#include<string.h>
int c[105],dp[45005];
inline int max(int a,int b){return a>b?a:b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n,m,sum=0;scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",c+i),sum+=c[i];
        memset(dp,0,sizeof dp);m=sum/2;
        for(int i=0;i<n;i++)
            for(int j=m;j>=c[i];j--)
                dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
        printf("%d\n",sum-dp[m]*2);
    }
    return 0;
}