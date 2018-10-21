const int maxn=55;
bool map[maxn][maxn];
int dp[maxn],que[maxn][maxn];
int n,ans_clique;
bool ans[maxn],now[maxn];
void dfs(int u,int now_clique){
    if(!u){
        if(ans_clique<now_clique){
            ans_clique=now_clique;
            memcpy(ans,now,sizeof now);
        }return;
    }
    for(int i=0;i<u;i++){
        int k=que[now_clique][i],cnt=0;
        if(now_clique+n+1-k<=ans_clique)return;
        if(now_clique+dp[k]<=ans_clique)return;
        now[k]=true;
        for(int j=i+1;j<u;j++)
            if(map[k][que[now_clique][j]])
                que[now_clique+1][cnt++]=que[now_clique][j];
        dfs(cnt,now_clique+1);
        now[k]=false;
    }
}
int maxclique(){
    dp[n]=ans_clique=1;
    for(int i=n-1;i>=1;i--){
        int u=0;
        for(int j=i+1;j<=n;j++)
            if(map[i][j])que[1][u++]=j;
        now[i]=true;dfs(u,1);now[i]=false;
        dp[i]=ans_clique;
    }return ans_clique;
}