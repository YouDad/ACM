//https://www.nowcoder.com/acm/contest/161/C
#include<stdio.h>
const int mod=1e9+7,maxn=500005;
long long f[maxn],g[maxn],r[maxn],p[maxn];
int m[maxn],n,L,M,sum;
void solve(){
    f[0]=1;g[0]=0;sum=0;
    for(int i=1;i<=n;i++){
        sum+=m[i];
        for(int j=sum;~j;j--){
            g[j]=g[j]*(mod+1-p[i])%mod;
            f[j]=f[j]*(mod+1-p[i])%mod;
            if(j>=m[i]){
                f[j]=(f[j]+p[i]*f[j-m[i]])%mod;
                g[j]=(g[j]+p[i]*(g[j-m[i]]+
                m[i]*r[i]%mod*f[j-m[i]]%mod)%mod)%mod;
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&L,&M);
    for(int i=1;i<=n;i++){
        scanf("%d%lld%lld",m+i,r+i,p+i);
        r[i]=r[i]*570000004%mod;
        p[i]=p[i]*570000004%mod;
    }solve();
    long long ans=0;
    for(int i=L;i<=sum;i++)
        ans=(ans+M*f[i]%mod-g[i])%mod;
    printf("%lld\n",(ans+mod)%mod);
}