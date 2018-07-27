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
lnt catalan(int x)
{
    return C(2*x,x)/(x+1);
}
lnt mzk[maxn];
void init_Motzkin()
{
    mzk[1]=1;
    mzk[2]=2;
    for(int i=3;i<maxn-2;i++)
        mzk[i]=((2*i+1)*mzk[i-1]%mod+(3*i-3)*mzk[i-2]%mod)*inv[i+2],mzk[i]%=mod;
}