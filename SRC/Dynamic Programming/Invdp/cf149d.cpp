#include<stdio.h>
#include<string.h>
char s[705];
int ss[405],top,f[705];
long long dp[705][705][3][3];
const int mod=1e9+7,black=0,blue=1,red=2,all=3;
bool can(int a,int b){return !a||!b||a!=b;}
long long dfs(int i,int j,int x,int y){
    long long&now=dp[i][j][x][y];
    if(~now)return now;
    if(i>=j)return now=0;
    long long ans=0;
    if(f[i]==j){
        if(!x&&y||!y&&x){
            if(i+1==j)return now=1;
            for(int a=0;a<all;a++)
                for(int b=0;b<all;b++)
                    if(can(a,x)&&can(b,y))
                        ans+=dfs(i+1,j-1,a,b);
        }
    }else{
        for(int a=0;a<all;a++)
            for(int b=0;b<all;b++)
                if(can(a,b))
                    ans+=dfs(i,f[i],x,a)*dfs(f[i]+1,j,b,y)%mod;
    }return now=ans%mod;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    gets(s);int i;
    for(i=0;s[i];i++)
        (s[i]=='('?ss[top++]:f[ss[--top]])=i;
    memset(dp,-1,sizeof dp);
    long long ans=0;
    for(int a=0;a<all;a++)
        for(int b=0;b<all;b++)
            ans+=dfs(0,i-1,a,b);
    printf("%I64d\n",ans%mod);
    return 0;
}