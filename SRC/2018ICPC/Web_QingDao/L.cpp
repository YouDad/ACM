#include<stdio.h>
#include<algorithm>
int a[100005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        std::sort(a,a+n);
        int sum=0,ans=0,k=1;
        for(int i=0;i<n;i++){
            while(i<n&&a[i]<(1<<k))sum++,i++;
            if(sum>ans)ans=sum;
            k++;sum=0;i--;
        }
        printf("%d\n",ans);
    }
    return 0;
}