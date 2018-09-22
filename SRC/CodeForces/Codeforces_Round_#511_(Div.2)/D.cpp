#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    long long n,m;
    scanf("%I64d%I64d",&n,&m);
    if(n>m)n^=m^=n^=m;
    if(n>=3)printf("%I64d\n",n*m-n*m%2);
    else if(n==1)printf("%I64d\n",m-(m%6>3?6-m%6:m%6));
    else if(m==2)puts("0");
    else if(m==3||m==7)printf("%I64d\n",n*m-2);
    else printf("%I64d\n",n*m);
    return 0;
}