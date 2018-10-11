#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    long long n,m,min=0;
    scanf("%I64d%I64d",&n,&m);
    while(min*(min-1)/2<m)min++;
    printf("%I64d %I64d\n",n-m*2<0?0:n-m*2,n-min);
    return 0;
}