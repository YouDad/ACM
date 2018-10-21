#include<stdio.h>
const int maxn=55;
bool map[maxn][maxn];
int dp[maxn],que[maxn][maxn];
int n,ans_clique;
bool ans[maxn],vis[maxn];
void dfs(int u,int now_clique){
    if(!u){
        if(ans_clique<now_clique){
            ans_clique=now_clique;
            memcpy(ans,vis,sizeof vis);
        }return;
    }
    for(int i=0;i<u;i++){
        int k=que[now_clique][i],cnt=0;
        if(now_clique+n+1-k<=ans_clique)return;
        if(now_clique+dp[k]<=ans_clique)return;
        vis[k]=true;
        for(int j=i+1;j<u;j++)
            if(map[k][que[now_clique][j]])
                que[now_clique+1][cnt++]=que[now_clique][j];
        dfs(cnt,now_clique+1);
        vis[k]=false;
    }
}
int maxclique(){
    dp[n]=ans_clique=1;
    for(int i=n-1;i>=1;i--){
        int u=0;
        for(int j=i+1;j<=n;j++)
            if(map[i][j])que[1][u++]=j;
        vis[i]=true;dfs(u,1);vis[i]=false;
        dp[i]=ans_clique;
    }return ans_clique;
}
int main(){int m;
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m)){
        memset(map,true,sizeof map);
        memset(vis,false,sizeof vis);
        for(int i=0,l,r;i<m;i++){
            scanf("%d%d",&l,&r);
            map[l][r]=map[r][l]=false;
        }printf("%d\n",n-maxclique());
    }
    return 0;
}