#include<stdio.h>
#include<string.h>
const int maxm=30*29/2,INF=0x7e7e7e7e;
const float inf=*(float*)&INF;
int tks,n,m,src,dist;
int u[maxm],v[maxm],w[maxm];
float t[8],dp[1<<10][31];
inline void selmin(float&a,float b){if(a>b)a=b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%d%d%d%d%d",&tks,&n,&m,&src,&dist)){
        if(!tks&&!n&&!m&&!src&&!dist)break;
        for(int i=0;i<tks;i++)scanf("%f",t+i);
        for(int i=0;i<m;i++)scanf("%d%d%d",u+i,v+i,w+i);
        memset(dp,0x7e,sizeof dp);dp[(1<<tks)-1][src]=0;
        for(int i=(1<<tks)-1;~i;i--)
        for(int j=0;j<tks;j++)
        if(i&1<<j)
            for(int k=0;k<m;k++)
                selmin(dp[i^1<<j][u[k]],dp[i][v[k]]+w[k]/t[j]),
                selmin(dp[i^1<<j][v[k]],dp[i][u[k]]+w[k]/t[j]);
        float res=inf;
        for(int i=0;i<1<<tks;i++)selmin(res,dp[i][dist]);
        printf(res==inf?"Impossible\n":"%.3f\n",res);
    }
    return 0;
}