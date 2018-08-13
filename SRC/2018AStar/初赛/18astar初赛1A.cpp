#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int a[1005];
int main(){
    for(int n;~scanf("%d",&n);){
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        std::sort(a,a+n);
        for(int i=n-2;i>=1;i--)
            for(int j=i-1;j>=0;j--)
                if(abs(a[i]-a[i+1])<a[j]){
                    printf("%d\n",a[i]+a[i+1]+a[j]);
                    goto end;
                }
        puts("-1");
        end:;
    }
    return 0;
}