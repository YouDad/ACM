#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    long long l,r;
    scanf("%I64d%I64d",&l,&r);
    puts("YES");
    for(long long i=l;i<=r;i+=2)
        printf("%I64d %I64d\n",i,i+1);
    return 0;
}