/*
    线性递推板子
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<ll> VLL;
const int maxn=1e5+5;
const int maxm=1e6+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
namespace linear_seq{
    const int N=10005;
    ll res[N],_c[N],_md[N];
    std::vector<int> Md;
    ll inv(ll base){
        ll ret=1;
        ll index=mod-2;
        base%=mod;
        for(;index;index>>=1){
            if(index&1)
                ret=ret*base%mod;
            base=base*base%mod;
        }
        return ret;
    }
    ll solve(ll n,VLL a,VLL b){ // a 系数 b 初值 b[n+1]=a[0]*b[n]+...
        ll ans=0,pnt=0;
        int k=a.size();
        for(int i=0;i<k;i++)
            _md[k-1-i]=-a[i],
            _md[k]=1;
        Md.clear();
        for(int i=0;i<k;i++)
            if(_md[i])
                Md.push_back(i);
        for(int i=0;i<k;i++)
            res[i]=0;
        res[0]=1;
        while((1ll<<pnt)<=n)
            pnt++;
        for(int p=pnt;p>=0;p--){
            for(int i=0;i<k+k;i++)
                _c[i]=0;
            for(int i=0;i<k;i++)
                if(res[i])
                    for(int j=0;j<k;j++)
                        _c[i+j]=(_c[i+j]+res[i]*res[j])%mod;
            for(int i=k+k-1;i>=k;i--)
                if(_c[i])
                    for(int j=0;j<Md.size();j++)
                        _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
            for(int i=0;i<k;i++)
                 res[i]=_c[i];
            if((n>>p)&1){
                for(int i=k-1;i>=0;i--)
                     res[i+1]=res[i];res[0]=0;
                for(int j=0;j<Md.size();j++)
                    res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%mod;
            }
        }
        for(int i=0;i<k;i++)
             ans=(ans+res[i]*b[i]+mod)%mod;
        return ans;
    }
    int gao(VLL a,ll n) {
        VLL c(1,1),B(1,1);
        int L=0,m=1,b=1;
        for(int n=0;n<a.size();n++){
            ll d=0;
            for(int i=0;i<L+1;i++)
                d=(d+c[i]*a[n-i])%mod;
            if(d==0)
                ++m;
            else if(2*L<=n){
                VLL tmp=c;
                ll tc=mod-d*inv(b)%mod;
                while (c.size()<B.size()+m)
                    c.push_back(0);
                for(int i=0;i<B.size();i++)
                    c[i+m]=(c[i+m]+tc*B[i])%mod;
                L=n+1-L; B=tmp; b=d; m=1;
            }
            else{
                ll tc=mod-d*inv(b)%mod;
                while(c.size()<B.size()+m)
                    c.push_back(0);
                for(int i=0;i<B.size();i++)
                    c[i+m]=(c[i+m]+tc*B[i])%mod;
                ++m;
            }
        }
        c.erase(c.begin());
        for(int i=0;i<c.size();i++)
            c[i]=(mod-c[i])%mod;
        return solve(n,c,VLL(a.begin(),a.begin()+c.size()));
    }
};


int main(){
    int n,k;
    ll num;
    while (~scanf("%d %d",&n,&k)){
        VLL a,b;
        for(int i=0;i<n;i++){
            scanf("%lld",&num);
            b.push_back(num);
        }
        for(int i=0;i<n;i++){
            scanf("%lld",&num);
            a.push_back(num);
        }
        printf("%lld\n",linear_seq::solve(k-1,a,b));
    }
    return 0;
}