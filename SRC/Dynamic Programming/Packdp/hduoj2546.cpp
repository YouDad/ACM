#include<stdio.h>
#include<string.h>
const int maxn=1005;
int c[maxn],dp[maxn];
inline int max(int a,int b){return a>b?a:b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++)
            scanf("%d",c+i);
        int m;scanf("%d",&m);
        if(m<5){printf("%d\n",m);continue;}
        int maxc=c[0],maxi=0;
        for(int i=1;i<n;i++)
            if(c[i]>maxc)
                maxc=c[i],maxi=i;
        c[maxi]=0;
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++)
            for(int j=m-5;j>=c[i];j--)
                dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
        printf("%d\n",m-dp[m-5]-maxc);
    }
    return 0;
}