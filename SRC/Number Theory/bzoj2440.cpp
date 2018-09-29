#include<stdio.h>
typedef long long ll;
const int maxn=100000;
int miu[maxn],p[maxn],cnt;
bool vis[maxn];
void sieve(){
    miu[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            p[cnt++]=i;
            miu[i]=-1;
        }
        for(int j=0;j<cnt&&i*p[j]<maxn;j++){
            vis[i*p[j]]=true;
            if(i%p[j]==0){
                break;
            }miu[i*p[j]]=-miu[i];
        }
    }
}
#define bin(L,R,mid,condition,ret) {    \
    int l=L,r=R;                        \
    while(l<=r){                        \
        int mid=(long long)l+r>>1;      \
        if(condition)ret=mid,r=mid-1;   \
        else l=mid+1;                   \
    }                                   \
}//bin(ans,1,2e9,x,k<=calc(x),ans);
int calc(int n){
    int ret=0;
    for(int i=1;i*i<=n;i++){
        ret+=miu[i]*n/i/i;
    }return ret;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    sieve();
    int T;scanf("%d",&T);
    while(T--){
        int k,ans;scanf("%d",&k);
        bin(ans,1,2e9,x,k<=calc(x),ans);
        printf("%d\n",ans);
    }return 0;
}