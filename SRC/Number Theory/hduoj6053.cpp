#include<stdio.h>
#include<string.h>
#include<algorithm>
const int maxn=100005,mod=1e9+7;
typedef long long ll;
ll qpow(ll x,int y){
    ll ret=1;
    while(y){
        if(y&1)ret=ret*x%mod;
        x=x*x%mod;y/=2;
    }
    return ret;
}
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
int arr[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    init();
    int t;scanf("%d",&t);
    for(int kase=1;t--;kase++){
        memset(arr,0,sizeof arr);
        int n,x;scanf("%d",&n);
        int min=mod,max=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            if(min>x)min=x;
            if(max<x)max=x;
            arr[x]++;
        }
        for(int i=1;i<=max;i++)
            arr[i]+=arr[i-1];
        ll ans=0;
        for(int i=2;i<=min;i++){
            if(miu[i]){
                ll fi=-miu[i];
                for(int j=1;i*j<=max;j++){
                    int l=i*j-1,r=i*j+i-1;if(r>max)r=max;
                    fi=fi*qpow(j,arr[r]-arr[l])%mod;
                }
                ans+=fi;
            }
        }
        printf("Case #%d: %lld\n",kase,(ans%mod+mod)%mod);
    }
    return 0;
}