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