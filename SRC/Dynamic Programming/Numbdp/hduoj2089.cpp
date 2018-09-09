#include<stdio.h>
#include<string.h>
int dp[9][2];
int dg[9];
int dfs(int p,int s,bool lim){
    if(!p)
        return 1;
    if(!lim&&~dp[p][s])
        return dp[p][s];
    int up=lim?dg[p]:9;
    int ans=0;
    for(int i=0;i<=up;i++){
        if(i==4||(s&&i==2))
            continue;
        ans+=dfs(p-1,i==6,lim&&i==up);
    }
    if(!lim)
        dp[p][s]=ans;
    return ans;
}
int dpfunc(int x){
    int i;
    for(i=1;x;i++,x/=10)
        dg[i]=x%10;
    return dfs(i-1,0,true);
}
int main(){
#ifdef LOCAL_DEBUG
	freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    memset(dp,-1,sizeof dp);
    for(int l,r;~scanf("%d%d",&l,&r)&&l+r;){
        printf("%d\n",dpfunc(r)-dpfunc(l-1));
    }
}