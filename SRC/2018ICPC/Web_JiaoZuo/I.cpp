#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
        puts((a%2)*(b%2)*(c%2)?"No":"Yes");
    return 0;
}