#include<stdio.h>
typedef long long ll;
const int mod=20101009,maxn=1e7+5;
int miu[maxn],p[maxn],pcnt,*iim;
bool pvis[maxn];
void init(int n){
    miu[1]=1;
    for(int i=2;i<=n;i++){
        if(!pvis[i]){
            p[pcnt++]=i;
            miu[i]=-1;
        }
        for(int j=0;j<pcnt&&i*p[j]<=n;j++){
            pvis[i*p[j]]=true;
            if(i%p[j])
                miu[i*p[j]]=-miu[i];
            else break;
        }
    }iim=miu;
    for(int i=1;i<=n;i++)
        iim[i]=(iim[i-1]+(ll)i*i%mod*miu[i]+mod)%mod;
    //iim[x]=sigma(i,1,x){i*i*miu[i]}
}
inline int min(int a,int b){return a<b?a:b;}
inline int S(int l,int r){
    return (ll)(l+r)*(r-l+1)/2%mod;
    //return l + l+1 + ... + r
}
int calc(int n,int m){
    int ret=0;
    for(int i=1,j;i<=n;i=j+1){
        j=min(n/(n/i),m/(m/i));
        (ret+=(ll)(iim[j]-iim[i-1]+mod)%mod
            *S(1,n/i)%mod*S(1,m/i)%mod)%=mod;
    }return ret;
    //ret=sigma(i,1,n){i*i*miu[i]*S(n/i)*S(m/i)}
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>m)n^=m^=n^=m;
    init(n);
    int ans=0;
    for(int i=1,j;i<=n;i=j+1){
        j=min(n/(n/i),m/(m/i));
        (ans+=(ll)S(i,j)*calc(n/i,m/i)%mod)%=mod;
    }
    //ans=sigma(d,1,n){d*calc(n/d,m/d)}
    printf("%d\n",ans);
    return 0;
}