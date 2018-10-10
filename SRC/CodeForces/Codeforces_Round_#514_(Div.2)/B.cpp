#include<stdio.h>
#include<string.h>
char s[1005][1005];
char t[1005][1005];
bool vis[1005][1005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m;
    scanf("%d%d%*c",&n,&m);
    for(int i=1;i<=n;i++)gets(s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='.'){
                vis[i-1][j-1]=true;
                vis[i-1][j]=true;
                vis[i-1][j+1]=true;
                vis[i+1][j-1]=true;
                vis[i+1][j]=true;
                vis[i+1][j+1]=true;
                vis[i][j+1]=true;
                vis[i][j-1]=true;
            }
    memset(t,'.',sizeof t);
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++)
            if(!vis[i][j]){
                t[i-1][j-1]='#';
                t[i-1][j]='#';
                t[i-1][j+1]='#';
                t[i+1][j-1]='#';
                t[i+1][j]='#';
                t[i+1][j+1]='#';
                t[i][j-1]='#';
                t[i][j+1]='#';
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]!=t[i][j])
                goto no;
    puts("YES");
    return 0;
    no:puts("NO");
    return 0;
}