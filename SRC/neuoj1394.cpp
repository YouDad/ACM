#include<bits/stdc++.h>
#define mod 1000000007
typedef long long type;
int n;
struct matrix
{
    const static int size=105;
    type a[size][size];
    matrix()
    {
        memset(a,0,sizeof(a));
    }
    matrix(const matrix&copy)
    {
        memcpy(a,copy.a,sizeof(a));
    }
    void scan()
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%I64d",&a[i][j]);
    }
    type max(){
        type ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(ans<a[i][j])
                    ans=a[i][j];
        return ans;
    }
    matrix operator*(matrix const&other)
    {
        matrix ret;
        int i,j,k;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    //max{k=1;k<=m;k++}dp[t][i][j]=dp[a][i][k]+dp[b][k][j] t==a+b
                    if(ret.a[i][j]<a[i][k]+other.a[k][j])
                        ret.a[i][j]=a[i][k]+other.a[k][j];
        return ret;
    }
    matrix&operator*=(matrix const&other)
    {
        *this=*this*other;
        return *this;
    }
    matrix operator^(type index)
    {
        matrix ret;
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
};
int main(){
    int m;
    while(~scanf("%d%d",&m,&n)){
        matrix ans;
        ans.scan();
        ans=ans^(m-1);
        printf("%lld\n",ans.max());
    }
    return 0;
}