#include<stdio.h>
// #include<string.h>
// #include<set>
// int sg[1005];
// void solve(){
//     memset(sg,0,sizeof sg);
//     for(int i=1;i<=1000;i++){
//         std::set<int>s;
//         for(int j=0;j<i;j++)
//             s.insert(sg[j]);
//         for(int j=1;j<i;j++)
//             s.insert(sg[j]^sg[i-j]);
//         while(s.count(sg[i]))sg[i]++;
//     }
//     for(int i=0;i<=1000;i++)
//         printf("(%d:%d)",i,sg[i]);
// }
int main(){
    // solve();
    int t;scanf("%d",&t);
    while(t--){
        int n,ai,nim=0;scanf("%d",&n);
        while(n--)
            scanf("%d",&ai),
            nim^=(ai+1)%4<2?(ai%2?ai+1:ai-1):ai;//1:1,2:2,3:4,4:3...
        puts(nim?"Alice":"Bob");
    }
    return 0;
}