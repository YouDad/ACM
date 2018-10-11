#include<stdio.h>
const int mod=1e9+7;
int f[105][10005];
inline int min(int a,int b){return a<b?a:b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,w,h;scanf("%d%d%d",&n,&w,&h);
    f[0][0]=1;
    for(int i=1;i<=w;i++)
        for(int j=0;j<=n;j++)
            if(f[i-1][j])
                for(int k=0;k<=h;k++)
                    if(j+k<=n)
                        (f[i][j+k]+=f[i-1][j])%=mod;
                    else break;
    int ans=-min(h,n/w)-1;
    for(int i=0;i<=n;i++)
        (ans+=f[w][i])%=mod;
    printf("%d\n",ans);
    return 0;
}