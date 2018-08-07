/*
第一手:2
先手输:3,5,8
先手赢:2,4,6,7,
嗯,是斐波那契数列的味道
*/
#include<stdio.h>
#include<algorithm>
long long f[55];
void solve(){
    f[0]=f[1]=1;
    for(int i=2;i<55;i++)
        f[i]=f[i-1]+f[i-2];
}
int main(){
    solve();
    long long n;
    while(scanf("%lld",&n)&&n)
        if(n==*std::lower_bound(f,f+55,n))
            puts("Second win");
        else
            puts("First win");
    return 0;
}