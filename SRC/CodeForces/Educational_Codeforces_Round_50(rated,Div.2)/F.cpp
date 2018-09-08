#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
long long v[1010000],vsize;
int main(){
    const long long maxn=1e18;
    int k=2;
    for(long long i=2;i<10000;i++){
        if(i==k*k){
            k++;continue;
        }
        long long j=i;
        while(j<=maxn/i/i){
            j*=i*i;
			v[vsize++]=j;
        }
    }
    for(long long i=10000;i<=1000000;i++)
        if(i==k*k)
			{k++;continue;}
        else
            v[vsize++]=i*i*i;
    std::sort(v,v+vsize);
    long long*end=std::unique(v,v+vsize);
    int t;scanf("%d",&t);
    while(t--){
        long long n;scanf("%I64d",&n);
        int pos=std::upper_bound(v,end,n)-v;
        printf("%I64d\n",n-pos-(int)sqrt(n*1.0));
    }
    return 0;
}