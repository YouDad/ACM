#include<stdio.h>
void func(int k,int n){
    if(n>=4){
        for(int i=0;i<n-n/2;i++)
            printf("%d ",k);
        func(k*2,n/2);
        return;
    }
    if(n==1)printf("%d",k);
    if(n==2)printf("%d %d",k,k*2);
    if(n==3)printf("%d %d %d",k,k,k*3);
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;
    while(~scanf("%d",&n))
        func(1,n),putchar('\n');
    return 0;
}