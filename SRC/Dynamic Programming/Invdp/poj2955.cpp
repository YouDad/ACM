#include<stdio.h>
#include<string.h>
const int maxn=105;
char s[maxn];int dp[maxn][maxn];
inline void selmax(int&a,int b){if(a<b)a=b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(gets(s)&&s[0]!='e'){
        int len=strlen(s);
        memset(dp,0,sizeof dp);
        for(int i=len-1;~i;i--)
        for(int j=i+1;j<len;j++){
            dp[i][j]=dp[i+1][j];
            for(int k=i+1;k<=j;k++)
                if(s[i]=='('&&')'==s[k]||s[i]=='['&&']'==s[k])
                    selmax(dp[i][j],dp[i+1][k-1]+dp[k+1][j]+2);
        }printf("%d\n",dp[0][len-1]);
    }
    return 0;
}