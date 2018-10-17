#include<stdio.h>
const int mod=1e9+7;
#define len(i) (r[i]-l[i]+1)
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b,int c){return min(min(a,b),c);}
inline int max(int a,int b,int c){return max(max(a,b),c);}
inline int min(int a,int b,int c,int d){return min(min(a,b,c),d);}
inline int max(int a,int b,int c,int d){return max(max(a,b,c),d);}
long long l[4],r[4];
long long intersection(int i,int j){
    return max(0,min(r[i],r[j])-max(l[i],l[j])+1);
}
long long intersection(int i,int j,int k){
    return max(0,min(r[i],r[j],r[k])-max(l[i],l[j],l[k])+1);
}
long long intersection(int i,int j,int k,int a){
    return max(0,min(r[a],r[i],r[j],r[k])-max(l[a],l[i],l[j],l[k])+1);
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        for(int i=0;i<4;i++)
            scanf("%lld%lld",l+i,r+i);
        long long ans=0;
        ans+=len(0)*len(1)%mod*len(2)%mod*len(3)%mod;
        ans-=len(2)*len(3)%mod*intersection(0,1)%mod;
        ans-=len(3)*len(0)%mod*intersection(1,2)%mod;
        ans-=len(0)*len(1)%mod*intersection(2,3)%mod;
        ans-=len(1)*len(2)%mod*intersection(3,0)%mod;
        ans+=len(0)*intersection(1,2,3)%mod;
        ans+=len(1)*intersection(0,2,3)%mod;
        ans+=len(2)*intersection(0,1,3)%mod;
        ans+=len(3)*intersection(0,1,2)%mod;
        ans+=intersection(0,1)*intersection(2,3)%mod;
        ans+=intersection(0,3)*intersection(1,2)%mod;
        ans-=intersection(0,1,2,3)*3%mod;
        ans%=mod;ans+=mod;ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}