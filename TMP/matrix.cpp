#include<string.h>
#define __add__(res,fir,sec) res+=fir+sec
#define __mul__(res,fir,sec) res+=fir*sec
template<typename type>
struct matrix{
#define FOR(i) for(int i=0;i<__size__;i++)
    static const int max_sz=2;
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
};typedef matrix<double> mat;
template<>int mat::__size__=0;//mat::set_calc_sz(2);