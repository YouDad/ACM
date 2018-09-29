#include<stdio.h>
typedef long long ll;
const int maxn=50005;
int miu[maxn],p[maxn],pcnt,*smiu;
bool pvis[maxn];
void init(){
    miu[1]=1;smiu=miu;
    for(int i=2;i<maxn;i++){
        if(!pvis[i]){
            p[pcnt++]=i;
            miu[i]=-1;
        }
        for(int j=0;j<pcnt&&i*p[j]<maxn;j++){
            pvis[i*p[j]]=true;
            if(i%p[j])
                miu[i*p[j]]=-miu[i];
            else break;
        }
        smiu[i]+=miu[i-1];
    }//smiu[x]=sigma(i,1,x){miu[i]}
}
inline int min(int a,int b){return a<b?a:b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    init();
    int T;scanf("%d",&T);
    while(T--){
        int n,m,d;
        scanf("%d%d%d",&n,&m,&d);
        if(n>m)n^=m^=n^=m;
        n/=d;m/=d;ll ans=0;
        for(int i=1,j;i<=n;i=j+1){
            j=min(n/(n/i),m/(m/i));
            ans+=(ll)(smiu[j]-smiu[i-1])*(n/i)*(m/i);
        }//ans=sigma(i,1,n){miu[i]*(n/i)*(m/i)}
        printf("%lld\n",ans);
    }
    return 0;
}