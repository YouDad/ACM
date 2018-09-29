#include<stdio.h>
typedef long long ll;
const int maxn=100005;
int miu[maxn],p[maxn],pcnt,*smiu;
bool pvis[maxn];
void init(int n){
    miu[1]=1;smiu=miu;
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
        smiu[i]+=miu[i-1];
    }//smiu[x]=simga(i,1,x){miu[i]}
}inline int min(int a,int b){return a<b?a:b;}
ll calc(int n,int m){
    ll ret=0;
    for(int i=1,j;i<=n;i=j+1){
        j=min(n/(n/i),m/(m/i));
        ret+=(ll)(smiu[j]-smiu[i-1])*(n/i)*(m/i);
    }return ret;//sigma(i,1,n){(n/i)*(m/i)*μ(i)}
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>m)n^=m^=n^=m;init(n);
    ll ans=0;
    for(int i=1,j,k=1;i<=n;i=j+1){
        j=min(n/(n/i),m/(m/i));
        ans+=(ll)(i+j)*(j-i+1)/2*calc(n/i,m/i);
    }//ans=sigma(d,1,n){d*calc(n/d,m/d)}
    printf("%lld\n",2*ans-(ll)n*m);
    return 0;
}