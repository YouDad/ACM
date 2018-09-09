// https://nanti.jisuanke.com/t/31460
#include<stdio.h>
#include<string.h>
typedef long long ll;
const int maxn=100005;
ll arr[(1<<18)+2],iarr[(1<<18)+2],M;
void update(ll*a,int x,ll val){
    for(a[x+=M]=val,x/=2;x;x/=2)
        a[x]=a[2*x]+a[2*x+1];
}
ll query(ll*a,int l,int r){
    ll ans=0;
    for(l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
        if(~l&1)ans+=a[l^1];
        if( r&1)ans+=a[r^1];
    }
    return ans;
}
int main(){
#ifdef LOCAL_DEBUG
	freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    for(int n,q;~scanf("%d%d",&n,&q);){
        M=1;while(M-2<n)M*=2;
        for(int i=M+1;i<=M+n;i++)
            scanf("%lld",arr+i);
        for(int i=M+1;i<=M+n;i++)
            iarr[i]=arr[i]*(M+n+1-i);
        for(int i=M;i;i--)
            arr[i]=arr[i*2]+arr[i*2+1],
            iarr[i]=iarr[i*2]+iarr[i*2+1];
        for(int op,l;q--;){
			ll r;
            scanf("%d%d%lld",&op,&l,&r);
            if(op==1){
                ll ret1=query(arr,l,r);
                ll ret2=query(iarr,l,r);
                printf("%lld\n",ret2-ret1*(n-r));
            }else{
                update(arr,l,r);
                update(iarr,l,(n+1-l)*r);
            }
        }
    }
    return 0;
}