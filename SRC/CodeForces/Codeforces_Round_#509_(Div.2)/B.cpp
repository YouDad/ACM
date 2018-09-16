#include<stdio.h>
#include<algorithm>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    long long a,b,c,d;
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
    long long g=std::__gcd(c,d);
    c/=g,d/=g;
    printf("%I64d\n",std::min(a/c,b/d));
    return 0;
}