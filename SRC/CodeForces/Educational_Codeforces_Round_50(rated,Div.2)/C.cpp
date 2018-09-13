#include<stdio.h>
#include<string.h>
typedef long long ll;
int dg[25];
ll dp[25][4];
ll dfs(int p,int s,int lim){
    if(!p)
        return 1;
    if(!lim&&~dp[p][s])
        return dp[p][s];
    int up=lim?dg[p]:9;
    if(s==3)up=0;
    ll ret=0;
    for(int i=0;i<=up;i++)
        if(i)
            ret+=dfs(p-1,s+1,lim&&i==up);
        else
            ret+=dfs(p-1,s,lim&&i==up);
    return lim?ret:dp[p][s]=ret;
}
ll dpfunc(ll x){
    int i;
    for(i=1;x;x/=10)
        dg[i++]=x%10;
    return dfs(i-1,0,1);
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    memset(dp,-1,sizeof dp);
    int t;scanf("%d",&t);
    while(t--){
        ll l,r;
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",dpfunc(r)-dpfunc(l-1));
    }
    return 0;
}