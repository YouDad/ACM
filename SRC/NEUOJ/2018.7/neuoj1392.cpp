#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 2005
long long fac[maxn],inv[maxn];
void inifv(){
	fac[0]=1;
    fac[1]=1;
    for(int i=2;i<maxn;i++)
        fac[i]=fac[i-1]*i%mod;
	inv[0]=1;
    inv[1]=1;
    for(int i=2;i<maxn;i++)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<maxn;i++)
        inv[i]=inv[i]*inv[i-1]%mod;
}
long long C(int n,int m){
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int main(){
    inifv();
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        long long a=C(n+m-4,n-2),b=C(n+m-4,n-3),c=C(n+m-4,m-3);
        printf("%lld\n",(a*a%mod-b*c%mod+mod)%mod);
    }
    return 0;
}