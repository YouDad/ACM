//neuqoj2082
#include<stdio.h>
//败态:10~18,163~324,2917~5832
//综上:败态:(9*18^i,18*18^i]
// int sg[10000];
// void solve(){
//     for(int i=2;i<10000;i++){
//         std::set<int>s;
//         //i是从i/j+i%j?1:0转移来的
//         //因为i/j*j不一定会>=i
//         for(int j=2;j<=9;j++)
//             s.insert(sg[i/j+(i%j?1:0)]);
//         while(s.count(sg[i]))sg[i]++;
//     }
//     for(int i=0;i<1000;i++)
//         printf("%d:%d  ",i,sg[i]);
// }
int main(){
    // solve();
    long long n,m;
    while(~scanf("%lld",&n)){
        m=18;while(n>m)m*=18;m/=18;
        puts(m*9+1<=n&&n<=m*18?"Ollie wins.":"Stan wins.");
    }
    return 0;
}