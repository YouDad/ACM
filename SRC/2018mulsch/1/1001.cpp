#include<stdio.h>
int main(){
    long long n,t;scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        if(n%3==0)
            n/=3,printf("%lld\n",n*n*n);
        else if(n%4==0)
            n/=4,printf("%lld\n",2*n*n*n);
        else
            puts("-1");
    }
    return 0;
}