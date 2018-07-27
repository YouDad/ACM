//sum[i] = a[1]+...+a[i] + delta[1]*i + delta[2]*(i - 1) + delta[3]*(i - 2)+...+delta[i]*1   // a[i]为原始数组
//       = sigma( a[x] ) + sigma( delta[x]  *  (i + 1 - x) )
//       = sigma( a[x] ) + (i + 1) * sigma( delta[x] ) - sigma( delta[x] * x )
//单点查询 区间修改
#include<stdio.h>
#include<string.h>
#define maxn 400005
#define mod 1000000007
#define lowbit(x) ((x)&(-(x)))
typedef long long treeArrtype;
struct treeArr
{
    treeArrtype c[maxn];
    treeArrtype d[maxn];
    treeArrtype di[maxn];
    treeArrtype queryarray(treeArrtype a[],int x)
    {
        treeArrtype ret=0;
        while(x)
        {
            ret+=a[x];
            ret%=mod;
            x-=lowbit(x);
        }
        return ret;
    }
    treeArrtype query(int x)
    {
        return (c[x]-c[x-1]+
            (x+1)*queryarray(d,x)-
            (x)*queryarray(d,x-1)+
            queryarray(di,x-1)-
            queryarray(di,x))%mod;
    }
    void updatearray(treeArrtype a[],int x,treeArrtype addval)
    {
        while(x<=n)
            a[x]+=addval,
            a[x]%=mod,
            x+=lowbit(x);
    }
    void update(int l,int r,treeArrtype addval)
    {
        updatearray(d,l,addval);
        updatearray(d,r+1,-addval);
        updatearray(di,l,l*addval);
        updatearray(di,r+1,(-r-1)*addval);
    }
}