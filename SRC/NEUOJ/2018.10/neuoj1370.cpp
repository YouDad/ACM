#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n,min=1e6,t;scanf("%d",&n);
        long long ans=0;
        for(int i=0;i<n;i++)
            scanf("%d",&t),ans+=t,
            min=t<min?t:min;
        printf("%lld\n",ans+min*(n-2));
    }
    return 0;
}