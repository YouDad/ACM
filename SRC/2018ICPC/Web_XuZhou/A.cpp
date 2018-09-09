// https://nanti.jisuanke.com/t/31453
#include<stdio.h>
typedef long long ll;
const int mod=1e9+7;
ll pow(ll x,ll y){
    ll ret=1;
    for(;y;y/=2,x=x*x%mod)
        if(y&1)ret=ret*x%mod;
    return ret;
}
int main(){
#ifdef LOCAL_DEBUG
	freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t,n,k;scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        ll ans,_2k=pow(2,k);
        ans=_2k*(n%2?1:_2k-1)%mod;
        for(int i=4-n%2;i<=n;i+=2)
            ans+=_2k*(_2k-2)%mod*pow(_2k-1,i-2)%mod;
        printf("%lld\n",ans%mod);
    }
    return 0;
}