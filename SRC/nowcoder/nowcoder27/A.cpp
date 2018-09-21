#include<stdio.h>
inline int min(int a,int b){return a<b?a:b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    printf("%d\n",n-min(n/2,n-n/2));
    return 0;
}