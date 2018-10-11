#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int s,a,b,c;
        scanf("%d%d%d%d",&s,&a,&b,&c);
        printf("%I64d\n",s/c+(long long)s/c/a*b);
    }
    return 0;
}