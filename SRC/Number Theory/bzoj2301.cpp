#include<stdio.h>
const int maxn=50005;
int miu[maxn],prime[maxn],cnt;
bool vis[maxn];
void init(){
    miu[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            miu[i]=-1;
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt&&i*prime[j]<maxn;j++){
            vis[i*prime[j]]=true;
            if(i%prime[j])
                miu[i*prime[j]]=-miu[i];
            else break;
        }
        miu[i]+=miu[i-1];
    }
}
int min(int a,int b){return a<b?a:b;}
int calc(int n,int m){
    if(n>m)n^=m^=n^=m;
    int ans=0;
    for(int i=1,j;i<=n;i=j+1){
        j=min(n/(n/i),m/(m/i));
        ans+=(miu[j]-miu[i-1])*(n/i)*(m/i);
    }
    return ans;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    init();
    int t;scanf("%d",&t);
    while(t--){
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        --a/=k,b/=k,--c/=k,d/=k;
        printf("%d\n",calc(b,d)+calc(a,c)-calc(b,c)-calc(a,d));
    }
    return 0;
}