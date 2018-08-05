//neuqoj2088
#include<stdio.h>
#include<math.h>
long long M;
long long mul(long long a,long long b){
    long long tmp=(a*b-(long long)((long double)a/M*b+1.0e-8)*M);
    return tmp<0?tmp+M:tmp;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a2,a1,a0,m0,m1,c,k;
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a0,&a1,&m0,&m1,&c,&M,&k);
        long long ans=mul(a0,a1);
        for(int i=2;i<=k;i++){
            a2=(mul(m0,a1)+mul(m1,a0)+c)%M;
            ans=mul(ans,a2);
            a0=a1;a1=a2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}