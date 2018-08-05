//neuqoj2068
#include<stdio.h>
#include<algorithm>
int a[1000005];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        std::sort(a,a+n);
        int ans=1;
        for(int i=1;i<n;i++)
            if(a[i]-a[i-1]>m)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}