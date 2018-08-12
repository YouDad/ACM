//neuqoj2122
#include<stdio.h>
#include<string.h>
const int maxn=3e5+5,mod=1e9+7;
long long s[maxn];
int main(){
    //freopen("2.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)){
        int t;s[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&t);
            s[i]=(s[i-1]+t)%mod;
        }
        long long ans=0,content=s[n];
        for(int i=1;i<=n;i++){
            scanf("%d",&t);
            ans=(ans+content*t)%mod;
            content=(content-s[i]+s[n-i])%mod;
            content=(content+mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}