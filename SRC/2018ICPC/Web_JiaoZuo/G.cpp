// https://nanti.jisuanke.com/t/31716
#include<stdio.h>
typedef long long ll;
const int mod=1e9+7;
ll pow(ll x,ll y){
    ll ret=1;y%=mod;
    while(y){
        if(y&1)ret=ret*x%mod;
        x=x*x%mod;y/=2;
    }
    return ret;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d%*c",&t);
    while(t--){
        ll y=0;char c;
        while((c=getchar())!='\n'&&c!=EOF)
            y=(y*10+c-'0')%(mod-1);
        printf("%lld\n",pow(2,y-1+mod));
    }
    return 0;
}