#include<stdio.h>
typedef long long ll;
ll f(ll n,int p){
    ll ret=0;
    while(n>=p)
        ret+=n/p,n/=p;
    return ret;
}
inline void selmin(ll&a,ll b){if(a>b)a=b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    ll n;int p;
    scanf("%lld%d",&n,&p);
    ll ans=0x3f3f3f3f3f3f3f3f;
    int cnt;
    for(int i=2;i<=p;i++){
        if(p%i==0){
            for(cnt=0;p%i==0;cnt++)p/=i;
            selmin(ans,f(n,i)/cnt);
        }
    }
    printf("%lld\n",ans);
    return 0;
}