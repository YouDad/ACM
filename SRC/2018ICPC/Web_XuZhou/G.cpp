// https://nanti.jisuanke.com/t/31459
#include<stdio.h>
#include<string.h>
#include<algorithm>
const int maxn=50005;
typedef int Array[(1<<17)+2];
int max(int x,int y){return x>y?x:y;}
#define upd(pos,lazy) arr[pos]=max(lazy,arr[pos]),lz[pos]=max(lazy,lz[pos])
struct segtree{
    Array arr,lz;
    int M,ss[30],top,ans,L,R;
    void init(int n){
        memset(arr,0,sizeof arr);
        memset(lz,0,sizeof lz);
        M=1;while(M-2<n)M*=2;
    }
    bool lzdown(int u){
        if(u>M)u/=2;
        for(top=0;u;u/=2)ss[top++]=u;
        while(top--)
            if(lz[u=ss[top]])
                upd(u*2,lz[u]),upd(u*2+1,lz[u]),lz[u]=0;
        return true;
    }
    void update(int l,int r,int val){
        for(L=R=0,l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
            if(~l&1&&(L||lzdown(L=l^1)))upd(l^1,val);
            if( r&1&&(R||lzdown(R=r^1)))upd(r^1,val);
        }
        for(L/=2;L;L/=2)arr[L]=max(arr[L*2],arr[L*2+1]);
        for(R/=2;R;R/=2)arr[R]=max(arr[R*2],arr[R*2+1]);
    }
    int query(int x){
        lzdown(x+=M);
        return arr[x];
    }
}v,h;
typedef int array[maxn];
array x,sortedx,y,sortedy;
int main(){
#ifdef LOCAL_DEBUG
	freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    for(int n;~scanf("%d",&n);){
        for(int i=0;i<n;i++)
            scanf("%d%d",x+i,y+i);
        memcpy(sortedx,x,n*4);
        memcpy(sortedy,y,n*4);
        std::sort(sortedx,sortedx+n);
        std::sort(sortedy,sortedy+n);
        long long ans=0;
        v.init(n+1);h.init(n+1);
        for(int i=n-1;~i;i--){
            int xp=std::lower_bound(sortedx,sortedx+n,x[i])-sortedx+1;
            int yp=std::lower_bound(sortedy,sortedy+n,y[i])-sortedy+1;
            ans+=x[i]+y[i]-h.query(xp)-v.query(yp);
            h.update(1,xp,y[i]);
            v.update(1,yp,x[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}