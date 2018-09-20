#include<stdio.h>
#include<string.h>
const int maxn=1005;
int c[maxn],v[maxn],dp[maxn];
inline int max(int a,int b){return a>b?a:b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n,m;scanf("%d%d",&n,&m);
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++)
            scanf("%d",v+i);
        for(int i=0;i<n;i++)
            scanf("%d",c+i);
        for(int i=0;i<n;i++)
            for(int j=m;j>=c[i];j--)
                dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
        printf("%d\n",dp[m]);
    }
    return 0;
}