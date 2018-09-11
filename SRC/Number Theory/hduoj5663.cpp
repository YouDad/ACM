#include<stdio.h>
const int maxn=1e7+5;
int miu[maxn],prime[maxn],cnt;
bool vis[maxn];
void init(){
    miu[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            miu[i]=-1;
        }
        for(int j=0;j<cnt&&i*prime[j]<maxn;j++){
            vis[i*prime[j]]=true;
            if(i%prime[j])
                miu[i*prime[j]]=-miu[i];
            else
                break;
        }
    }
}
int sum[maxn];
int min(int a,int b){return a<b?a:b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    init();
    for(int i=1;i*i<maxn;i++)
        for(int j=1;i*i*j<maxn;j++)
            sum[i*i*j]+=miu[j];
    for(int i=1;i<maxn;i++)
        sum[i]+=sum[i-1];
    int t;scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d%d",&n,&m);
        if(n>m)n^=m^=n^=m;
        long long ans=0,i,j;
        for(i=(j=0)+1;i<=n;i=j+1){
            j=min(n/(n/i),m/(m/i));
            ans+=(n/i)*(m/i)*(sum[j]-sum[i-1]);
        }
        printf("%lld\n",1LL*n*m-ans);
    }
    return 0;
}