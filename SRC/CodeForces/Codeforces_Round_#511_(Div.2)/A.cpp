#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    if(n%3==0)
        printf("1 1 %d\n",n-2);
    else if(n%3==1)
        printf("1 2 %d\n",n-3);
    else
        printf("2 2 %d\n",n-4);
    return 0;
}