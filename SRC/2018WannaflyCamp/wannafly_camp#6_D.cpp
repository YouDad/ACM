//neuqoj2119
#include<stdio.h>
int main(){
    long long n,min,t,sum;
    while(~scanf("%lld",&n)){
        sum=0,min=1e9+7;
        for(int i=0;i<n;i++)
            scanf("%lld",&t),
            sum+=t,min=t<min?t:min;
        printf("%lld\n",min*(n-2)+sum);
    }
    return 0;
}