//neuqoj2124
#include<stdio.h>
int main(){
    int n;
    while(~scanf("%d",&n)){
        long long sigma=0,pi=1,ai;
        const int mod=998244353;
        for(int i=0;i<n;i++){
            scanf("%lld",&ai);
            sigma=(sigma+ai*(ai+1)/2)%mod;
            pi=pi*(ai+1)%mod;
        }
        printf("%lld\n",(sigma+pi)%mod);
    }
    return 0;
}