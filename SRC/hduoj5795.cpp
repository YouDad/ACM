#include<stdio.h>
// #include<string.h>
// #include<set>
// int sg[105];
// void solve(){
//     memset(sg,0,sizeof sg);
//     for(int i=1;i<=100;i++){
//         std::set<int>s;
//         for(int j=0;j<i;j++)
//             s.insert(sg[j]);
//         for(int j=1;j<i-1;j++)
//             for(int k=1;k<i-j;k++)
//                 s.insert(sg[j]^sg[k]^sg[i-j-k]);
//         while(s.count(sg[i]))sg[i]++;
//     }
//     for(int i=0;i<=100;i++)
//         // if(i!=sg[i])
//         printf("(%d:%d)",i,sg[i]);
// }
int main(){
    // solve();
    int t;scanf("%d",&t);
    while(t--){
        int n,ai,nim=0;scanf("%d",&n);
        while(n--)
            scanf("%d",&ai),
            nim^=(ai+1)%8<2?(ai%2?ai+1:ai-1):ai;//7:8,8:7,15:16,16:15...
        puts(nim?"First player wins.":"Second player wins.");
    }
    return 0;
}