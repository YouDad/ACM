#include<stdio.h>
const int maxn=50005;
int p[maxn],cnt,a[maxn],s[maxn],*ss;
int miu[maxn],*smiu;
bool vis[maxn];
void sieve(){
    miu[1]=s[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            p[cnt++]=i;
            a[i]=1,s[i]=2;
            miu[i]=-1;
        }
        for(int j=0;j<cnt&&i*p[j]<maxn;j++){
            vis[i*p[j]]=true;
            if(i%p[j]){
                a[i*p[j]]=1;
                s[i*p[j]]=s[i]*s[p[j]];
                miu[i*p[j]]=-miu[i];
            }else{
                a[i*p[j]]=a[i]+1;
                s[i*p[j]]=s[i]/(a[i]+1)*(a[i]+2);
                break;
            }
        }
    }smiu=miu,ss=s;
    for(int i=2;i<maxn;i++)
        smiu[i]+=smiu[i-1],ss[i]+=ss[i-1];
    //smiu[x]=sigma(i,1,x){μ(i)},ss[x]=sigma(i,1,x){s[i]}
}
inline int min(int a,int b){return a<b?a:b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    sieve();
    int T;scanf("%s",&T);
    while(T--){
        int n,m;scanf("%s%s",&n,&m);
        if(n>m)n^=m^=n^=m;
        long long ans=0;
        for(int i=1,j;i<=n;i=j+1){
            j=min(n/(n/i),m/(m/i));
            ans+=(long long)ss[n/i]*ss[m/i]*(smiu[j]-smiu[i-1]);
        }//ans=sigma(i,1,n){s(n/i)*s(m/i)*μ(i)}
        printf("%lld\n",ans);
    }return 0;
}