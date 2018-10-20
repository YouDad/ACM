#include<stdio.h>
#include<string.h>
#include<vector>
int n,m;const int maxn=105;
int deg[maxn];
bool map[maxn][maxn];
std::vector<int>ans,now;
void dfs(int u){
    if(u>n&&ans.size()<now.size())ans=now;
    if(u>n)return;
    if(!deg[u]){
        now.push_back(u);
        dfs(u+1);return;
    }int i;
    for(i=0;i<now.size();i++)
        if(map[now[i]][u]){
            dfs(u+1);return;
        }
    now.push_back(u);
    dfs(u+1);now.pop_back();dfs(u+1);
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
		now.clear();ans.clear();
        memset(map,false,sizeof map);
        memset(deg,0,sizeof deg);
        for(int i=1,u,v;i<=m;i++){
            scanf("%d%d",&u,&v);
            if(!map[u][v]){
                map[u][v]=map[v][u]=true;
                deg[u]++;deg[v]++;
            }
        }dfs(1);printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
    }
    return 0;
}