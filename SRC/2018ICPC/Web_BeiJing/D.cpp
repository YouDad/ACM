#include<stdio.h>
int a[1000005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n,k,t;scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)scanf("%d",&t),a[i]-=t;
        long long sum=0;int ans,i=0,j=0;
        while(i!=n&&j-i!=n){
            sum+=a[j++%n];
            while(i<n&&sum<-k)
                sum-=a[i++];
        }printf("%d\n",i==n?-1:i+1);
    }
    return 0;
}