//很好的题解https://www.cnblogs.com/kuangbin/archive/2013/07/22/3204654.html
//随便推一下就知道和n的奇偶性有关系
#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)&&n)
        puts(n%2?"ailyanlu":"8600");
    return 0;
}