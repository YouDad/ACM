// https://nanti.jisuanke.com/t/31721
#include<stdio.h>
#include<string.h>
#include<map>
#define mod 1000000007
typedef long long ll;
const ll def[]={
    0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,
    0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,
    1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
    1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
    1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
    0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
    0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
    0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
    0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
    0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
    0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
    0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
    0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,
    0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0
};
struct matrix{
    ll a[20][20];
    matrix(){
        memset(a,0,sizeof(a));
    }
    matrix(int x){
        memset(a,0,sizeof(a));
        for(int i=0;i<20;i++)
            a[i][i]=1;
    }
    matrix(const matrix&copy){
        memcpy(a,copy.a,sizeof(a));
    }
    void special(){
        memcpy(a,def,sizeof a);
    }
    ll sum(){
        ll ret=0;
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                ret+=a[i][j];
        return ret%mod;
    }
    matrix operator+(const matrix&other){
        matrix ret;
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                for(int k=0;k<20;k++)
                    ret.a[i][j]=(ret.a[i][j]+a[i][j]+other.a[i][j])%mod;
        return ret;
    }
    matrix operator*(const matrix&other){
        matrix ret;
        int i,j,k;
        for(i=0;i<20;i++)
            for(j=0;j<20;j++)
                for(k=0;k<20;k++)
                    ret.a[i][j]+=a[i][k]*other.a[k][j],
					ret.a[i][j]%=mod;
        return ret;
    }
    matrix&operator*=(const matrix&other){*this=*this*other;
        return*this;
    }
    matrix operator^(ll index){
        matrix ret(1);
        matrix base(*this);
        while(index){
            if(index&1)
                ret*=base;
            base*=base;
            index>>=1;
        }
        return ret;
    }
}m,two[34];
std::map<ll,ll>map;
ll pow(ll y){
    if(map.count(y))return map[y];
    matrix ret(1);
    for(int i=0;i<34;i++)
        if(y&(1LL<<i))
            ret*=two[i];
    return map[y]=ret.sum();
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    m.special();
    two[0]=m;
    for(int i=1;i<34;i++)
        two[i]=two[i-1]*two[i-1];
    int t;scanf("%d",&t);
    while(t--){
        ll x;scanf("%lld",&x);
        if(x<=3)
            switch(x){
                case 1:puts("3");break;
                case 2:puts("9");break;
                case 3:puts("20");break;
            }
        else
            printf("%lld\n",pow(x-3));
    }
    return 0;
}