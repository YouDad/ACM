#include<stdio.h>
#include<string.h>
#include<algorithm>
int arr[1<<18],a[100005],sorted[100005];
int main(){
    for(int n,b,c;~scanf("%d%d%d",&n,&b,&c);){
        c=c<b?c:b;int M=1;while(M-2<n)M*=2;
        memset(arr,0,sizeof arr);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        memcpy(sorted,a,n*4);sorted[n]=-0x3f3f3f3f;
        std::sort(sorted,sorted+n+1);
        int sortlen=std::unique(sorted,sorted+n+1)-sorted;
        long long ans=0;
        for(int i=0;i<n;i++){
            int x=std::lower_bound(sorted,sorted+sortlen,a[i])-sorted;
            for(int l=M+x,r=M+n+1;l^r^1;l/=2,r/=2){
                if(~l&1)ans+=arr[l^1];
                if( r&1)ans+=arr[r^1];
            }
            for(arr[x+=M]++,x/=2;x;x/=2)arr[x]=arr[x*2]+arr[x*2+1];
        }printf("%lld\n",ans*c);
    }
    return 0;
}