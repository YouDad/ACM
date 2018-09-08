#include<stdio.h>
int main(){
    long long n,m;
    while(~scanf("%I64d%I64d",&n,&m))
        printf("%I64d\n",m/n+(m%n!=0));
    return 0;
}