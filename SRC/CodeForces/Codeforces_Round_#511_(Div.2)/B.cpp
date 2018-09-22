#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    int a,b,c=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        if(c<a+b)c=a+b;
    }printf("%d\n",c);
    return 0;
}