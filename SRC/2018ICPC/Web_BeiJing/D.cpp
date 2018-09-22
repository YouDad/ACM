#include<stdio.h>
int a[1000005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n,k,t;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=0;i<n;i++)
            scanf("%d",&t),a[i]-=t;
        long long sum=0;int ans;
        for(int i=0,j=0;;j++){
            sum+=a[j%n];
            while(i<n&&sum<-k)sum-=a[i++];
            if(i==n){
                ans=-1;break;
            }else if(j-i==n-1){
                ans=i+1;break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}