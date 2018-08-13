#include<stdio.h>
#include<algorithm>
#include<vector>
#define mod 1000000007
struct input{
    int n,k,i;
    input(int nn,int kk,int ii){n=nn,k=kk,i=ii;}
};
int dp[2][5005]={};
int ans[5005]={};
int main(){
    int n,k,c=0,id=0;
    std::vector<input>v;
    while(~scanf("%d%d",&n,&k))
        v.push_back(input(n,k,id++));
    std::sort(v.begin(),v.end(),[](input a,input b){
        return a.n<b.n;
    });
    dp[0][0]=1;
    for(int i=1;i<=v.back().n;i++)
    {
        int sum=0;
        for(int j=0;j<=5000;j++)
        {
            sum=(sum+dp[i-1&1][j])%mod;
            if(j>=i)sum=(sum+mod-dp[i-1&1][j-i])%mod;
            dp[i&1][j]=sum;
        }
        while(c<v.size()&&v[c].n==i)
            ans[v[c].i]=dp[i&1][v[c].k],c++;
    }
    for(int i=0;i<v.size();i++)
        printf("%d\n",ans[i]);
    return 0;
}