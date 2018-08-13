#include<stdio.h>
long long inv[1000005]={1,1};
const long long mod=1e9+7;
void init(){
    for(int i=2;i<1000001;i++)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<1000001;i++)
        inv[i]=inv[i-1]*inv[i]%mod;
}
int main(){
	init();
    int u,n;
    while(~scanf("%d",&n)){
        long long ans=1,sum=0;
        for(long long i=0;i<n;i++)
        {
            scanf("%d",&u);
            ans=ans*inv[u]%mod;
            sum+=u;
        }
        for(long long i=2;i<=sum;i++)
            ans=ans*i%mod;
        printf("%lld\n",ans);
    }
    return 0;
}