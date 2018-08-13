//neuqoj2098
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
long long maxk;
long long func(long long n,long long k){
    long long w;
    w=sqrt(n+0.0);
    maxk=w*2+2;
    while(true)
        if((maxk/2)*(maxk/2)+(maxk/2)+maxk%2*((maxk/2)+1)>n)
            maxk--;
        else
            break;
    k=maxk-k;
    if(k<w)
        return k+1;
    else
        return n/(maxk-k);
}
int main(){
    //freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        long long n,k;
        scanf("%lld%lld",&n,&k);
        printf("%lld %lld\n",maxk,func(n,k));
    }
    return 0;
}