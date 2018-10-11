#include<stdio.h>
#include<string.h>
const int maxn=15;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
int w[maxn],h[maxn],q[maxn];
int maxw[1<<maxn],maxh[1<<maxn],sumq[1<<maxn];
ll sumc[1<<maxn],f[maxn+1][1<<maxn],cost[1<<maxn];
inline void selmin(ll&a,ll b){if(a>b)a=b;}
inline void selmax(int&a,int b){if(a<b)a=b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",w+i,h+i,q+i);
    for(int k=1;k<1<<n;k++){
        for(int i=0;i<n;i++)if(k>>i&1){
            selmax(maxw[k],w[i]);
            selmax(maxh[k],h[i]);
            sumc[k]+=(ll)w[i]*h[i]*q[i];
            sumq[k]+=q[i];
        }
        cost[k]=(ll)maxw[k]*maxh[k]*sumq[k]-sumc[k];
    }
    memset(f,0x3f,sizeof f);f[0][0]=0;
    for(int i=1;i<=m;i++)
    for(int j=0;j<1<<n;j++)
    for(int k=j;k;k=--k&j)
        selmin(f[i][j],f[i-1][j-k]+cost[k]);
    ll ans=inf;
    for(int i=0;i<=m;i++)
        selmin(ans,f[i][(1<<n)-1]);
    printf("%lld\n",ans);
    return 0;
}