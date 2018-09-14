#include<stdio.h>
#include<string.h>
#include<algorithm>
const int maxn=40005;
int arr[1<<17],lz[1<<17],M,ss[32],top;
int max(int a,int b){return a>b?a:b;}
#define upd(pos,lazy) arr[pos]=max(arr[pos],lazy),lz[pos]=max(lz[pos],lazy)
bool lzdown(int u){
    if(u>M)u/=2;
    for(top=0;u;u/=2)ss[top++]=u;
    while(top--){
        u=ss[top];
        if(lz[u]){
            upd(u*2,lz[u]);
            upd(u*2+1,lz[u]);
            lz[u]=0;
        }
    }
    return true;
}
void update(int l,int r,int val){
    int L=0,R=0;
    for(l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
        if(~l&1)if(L||lzdown(L=l^1))upd(l^1,val);
        if( r&1)if(R||lzdown(R=r^1))upd(r^1,val);
    }
    for(L/=2;L;L/=2)arr[L]=max(arr[L*2],arr[L*2+1]);
    for(R/=2;R;R/=2)arr[R]=max(arr[R*2],arr[R*2+1]);
}
int a[maxn],b[maxn],sorted[maxn];
bool vis[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",a+i,b+i);
        memcpy(sorted,a+1,n*4);
        memcpy(sorted+n,b+1,n*4);
        std::sort(sorted,sorted+2*n);
        int sortlen=std::unique(sorted,sorted+2*n)-sorted;
        int end=sortlen;
        for(int i=1;i<sortlen;i++)
            if(sorted[i]-sorted[i-1]>1)
                sorted[end++]=sorted[i-1]+1;
        std::sort(sorted,sorted+(sortlen=end));
        memset(arr,0,sizeof arr);
        memset(lz,0,sizeof lz);
        M=1;while(M-1<sortlen)M*=2;
        for(int i=1;i<=n;i++){
            int lpos=std::lower_bound(sorted,sorted+sortlen,a[i])-sorted+1;
            int rpos=std::lower_bound(sorted,sorted+sortlen,b[i])-sorted+1;
            update(lpos,rpos,i);
        }
        for(int i=1;i<M;i++)
            if(lz[i])
                upd(i*2,lz[i]),
                upd(i*2+1,lz[i]);
        memset(vis,false,sizeof vis);
        for(int i=M+1;i<=M+sortlen;i++)
            vis[arr[i]]=true;
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=vis[i];
        printf("%d\n",ans);
    }
    return 0;
}