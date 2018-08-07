#include<string.h>
#include<stdio.h>
#include<set>
int sg[1005];
void solve(){
    memset(sg,0,sizeof sg);
    for(int i=1;i<=1000;i++){
        std::set<int>s;
        for(int j=0;i>=(1<<j);j++)
            s.insert(sg[i-(1<<j)]);
        while(s.count(sg[i]))sg[i]++;
    }
}
int main(){
    solve();
    int n;
    while(~scanf("%d",&n))
        puts(sg[n]?"Kiki":"Cici");
    return 0;
}