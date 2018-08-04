#include <bits/stdc++.h>
#define mkpr std::make_pair
const int maxn=1005;
int x[maxn],y[maxn];
long long z[maxn][maxn],dp[maxn][maxn];
int main(){
	// freopen("1.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        std::set<int>xset,yset;
        std::map<std::pair<int,int>,int>mp;
        int cntx=0,cnty=0,a,b,c;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(mp.count(mkpr(a,b))==0)
                mp[mkpr(a,b)]=c;
            else
                mp[mkpr(a,b)]+=c;
            if(xset.count(a)==0)
                xset.insert(a),x[++cntx]=a;
            if(yset.count(b)==0)
                yset.insert(b),y[++cnty]=b;
        }
        std::sort(x,x+ ++cntx);
        std::sort(y,y+ ++cnty);
        memset(z,0,sizeof(z));
        memset(dp,0,sizeof(dp));

        for(int i=1;i<cntx;i++)             //z=第i,j阶段时最大收益
            for(int j=1;j<cnty;j++){        //求出混吃等死的收益
                z[i][j]=z[i-1][j]+z[i][j-1]-z[i-1][j-1];
                if(mp.count(mkpr(x[i],y[j])))z[i][j]+=mp[mkpr(x[i],y[j])];
            }

        for(int i=0;i<cntx;i++)             //dp=第i,j阶段时最大分数
            for(int j=0;j<cnty;j++)         //求出努力奋斗的分数
                dp[i][j+1]=std::max(dp[i][j+1],dp[i][j]+z[i][j]*(y[j+1]-y[j]-1)+z[i][j+1]),
                dp[i+1][j]=std::max(dp[i+1][j],dp[i][j]+z[i][j]*(x[i+1]-x[i]-1)+z[i+1][j]);

        long long ans=0;
        for(int i=1;i<=cntx;i++)
            for(int j=1;j<=cnty;j++)
                ans=std::max(ans,dp[i][j]+(m-x[i]-y[j])*z[i][j]);   //dp值+剩余天数混吃等死
        printf("%lld\n",ans);
    }
    return 0;
}