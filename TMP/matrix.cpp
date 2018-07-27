#include<stdio.h>
#include<string.h>
#define mod 1000000007
typedef long long type;
int n;
struct matrix
{
    const static int size=5;
    type a[size][size];
    matrix()
    {
        memset(a,0,sizeof(a));
    }
    matrix(int x)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            a[i][i]=1;
    }
    matrix(matrix&copy)
    {
        memcpy(a,copy.a,sizeof(a));
    }
    void scan()
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%I64d",&a[i][j]);
    }
    void special()
    {

    }
    matrix operator+(matrix const&other)
    {
        matrix ret;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    ret.a[i][j]=(ret.a[i][j]+a[i][j]+other.a[i][j])%mod;
        return ret;
    }
    matrix operator*(matrix const&other)
    {
        matrix ret;
        int i,j,k;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    ret.a[i][j]+=a[i][k]*other.a[k][j],ret.a[i][j]%=mod;
        return ret;
    }
    matrix&operator*=(matrix const&other)
    {
        *this=*this*other;
        return *this;
    }
    matrix operator^(type index)
    {
        matrix ret(1);
        matrix base(*this);
        while(index)
        {
            if(index&1)
                ret*=base;
            base*=base;
            index>>=1;
        }
        return ret;
    }
    matrix sum(int x)//A+A^2+...+A^x
    {
        matrix A=*this;
        if(x==1)
            return A;
        if(x==2)
            return A*A+A;
        if(x&1)
            return (A^x)+sum(x-1);
        else
            return (e+A^(x/2))*sum(x/2);
    }
}e(1);