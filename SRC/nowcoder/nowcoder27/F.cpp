#include<stdio.h>
#include<string.h>
const int mod=998244353;
#define __add__(res,fir,sec) //res+=fir+sec
#define __mul__(res,fir,sec) (res+=fir*sec)%=mod
template<typename type>
struct matrix{
#define FOR(i) for(int i=0;i<__size__;i++)
    static const int max_sz=16;
    static int __size__;
    type a[max_sz][max_sz];
    typedef type(*ap)[max_sz];
    static void set_calc_sz(int sz){__size__=sz;}
    matrix(){}
    matrix(type x){
        FOR(i)FOR(j)a[i][j]=x;
    }
    matrix(const matrix&other){
        memcpy(a,other.a,sizeof a);
    }
    matrix operator+(const matrix&other){
        matrix ret(0);ap b=(ap)other.a,c=ret.a;
        FOR(i)FOR(j)FOR(k)__add__(c[i][j],a[i][j],b[i][j]);
        return ret;
    }
    matrix operator*(const matrix&other){
        matrix ret(0);ap b=(ap)other.a,c=ret.a;
        FOR(i)FOR(j)FOR(k)__mul__(c[i][j],a[i][k],b[k][j]);
        return ret;
    }
    matrix operator^(long long idx){
        matrix ret(0),base(*this);
        FOR(i)ret.a[i][i]=1;
        while(idx){
            if(idx&1)ret=ret*base;
            base=base*base;idx/=2;
        }return ret;
    }
#undef FOR
};typedef matrix<long long> mat;
template<>int mat::__size__=0;//mat::set_calc_sz(2);
int valid[16],cnt;
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    long long n;int m;
    scanf("%lld%d",&n,&m);
    int t=1<<m-1;memset(valid,-1,sizeof valid);
    for(int i=0;i<t;i++)
        if(__builtin_popcount(i)<=m/2)
            valid[i]=cnt++;
    mat::set_calc_sz(cnt);
    mat x(0);mat::ap a=x.a;
    for(int i=0;i<t;i++)if(~valid[i]){
        if(__builtin_popcount(2*i+1)<=m/2)
            a[valid[i]][valid[(2*i+1)%t]]=1;
        a[valid[i]][valid[2*i%t]]=1;
    }
    long long ans=0;x=x^n;
    for(int i=0;i<cnt;i++)
        ans+=a[i][i];
    printf("%lld\n",ans%mod);
    return 0;
}