#include<stdio.h>
typedef long long ll;
const int mod=998244353,maxn=5e6+5;
int f[maxn],p[maxn],cnt;
bool vis[maxn];
ll pow(ll x,int y){
    ll ret=1;
    for(;y;y/=2,x=x*x%mod)
        if(y&1)ret=ret*x%mod;
    return ret;
}
void init(int k){
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            p[cnt++]=i;
            f[i]=(pow(i,k)+mod-1)%mod;
        }
        for(int j=0;j<cnt&&i*p[j]<maxn;j++){
            vis[i*p[j]]=true;
            if(i%p[j])
                f[i*p[j]]=(ll)f[i]*f[p[j]]%mod;
            else{
                f[i*p[j]]=pow(p[j],k)*f[i]%mod;
                break;
            }
        }
    }
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m,k;
    scanf("%d%d",&m,&k);
    init(k);
    while(m--)
        scanf("%d",&n),
        printf("%d\n",f[n]);
    return 0;
}