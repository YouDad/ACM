#include<stdio.h>
int main(){
    int n,ans=0;scanf("%d",&n);
    while(n)n/=2,ans++;
    printf("%d\n",ans);
    return 0;
}