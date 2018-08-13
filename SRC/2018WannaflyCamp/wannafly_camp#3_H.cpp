//neuqoj2083
#include<stdio.h>
#define maxn 100000
typedef long long lnt;
const lnt mod=1e9+7;
lnt inv[maxn+5],fac[maxn+5];
void iniv()
{
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=maxn;i++)
        fac[i]=fac[i-1]*i%mod;
    ///inv[maxn]=pow(fac[maxn],mod-2);
    inv[maxn]=1;
    lnt base=fac[maxn];
    lnt index=mod-2;
    while(index){
        if(index&1)inv[maxn]=inv[maxn]*base%mod;
        base=base*base%mod;
        index>>=1;
    }
    ///
    for(int i=maxn-1;i>0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
}
lnt C(int n,int m)
{
    if(n-m<m)m=n-m;
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int main(){
    iniv();
    int n,m,t;scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++)scanf("%*d%*d");
        printf("%lld\n",C(n-1,m-1)*fac[m]%mod);
    }
    return 0;
}