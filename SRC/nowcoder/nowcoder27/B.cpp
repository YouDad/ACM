#include<stdio.h>
typedef long long ll;
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    ll n,ans=0;scanf("%lld",&n);
    for(ll i=1;i*i*i<=n;i++){
        ans+=1+n/i/i*3-i*3;//[i,i,i]x1 + [i,i,j]x3 (j>i)
        for(ll j=i+1;j*j<=n/i;j++)
            ans+=3+n/i/j*6-j*6;//[i,j,j]x3 + [i,j,k]x6 (k>j)
    }
    printf("%lld\n",ans%2333);
    return 0;
}