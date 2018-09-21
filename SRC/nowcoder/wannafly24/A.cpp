// https://www.nowcoder.com/acm/contest/186/A
#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m;
    while(~scanf("%d",&n)){
        int even=0;
        while(n--)
            scanf("%d",&m),
            even+=m%2==0;
        if(even)
            puts(even%2?"Bob":"Alice");
        else if(m!=1) puts("Alice");
        else puts("Bob");
    }
    return 0;
}