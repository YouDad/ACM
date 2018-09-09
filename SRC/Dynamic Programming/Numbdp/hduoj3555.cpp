#include<stdio.h>
#include<string.h>
typedef long long ll;
int dg[21];
ll dp[21][2];
ll dfs(int p,int s,bool lim){
    if(!p)
        return 1;
    if(!lim&&~dp[p][s])
        return dp[p][s];
    int up=lim?dg[p]:9;
    ll ans=0;
    for(int i=0;i<=up;i++){
        if(s&&i==9)
            continue;
        ans+=dfs(p-1,i==4,lim&&i==up);
    }
    return lim?ans:dp[p][s]=ans;
}
ll only49(ll x){
    int i;ll xx=x;
    for(i=1;x;i++,x/=10)
        dg[i]=x%10;
    return xx-dfs(i-1,0,true)+1;
}
int main(){
#ifdef LOCAL_DEBUG
	freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    memset(dp,-1,sizeof dp);
    int t;scanf("%d",&t);
    while(t--){
        ll num;scanf("%lld",&num);
        printf("%lld\n",only49(num));
    }
    return 0;
}