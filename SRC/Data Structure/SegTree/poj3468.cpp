#include<stdio.h>
int al[1<<18],ar[1<<18],M,ss[30],top,L,R;
long long arr[1<<18],lz[1<<18],ans;
#define upd(pos,lazy) lz[pos]+=lazy;arr[pos]+=(ar[pos]-al[pos]+1)*lazy
bool lzdown(int u){
    if(u>M)u/=2;
    for(top=0;u;u/=2)ss[top++]=u;
    while(top--){u=ss[top];
        if(lz[u])
            upd(u*2+0,lz[u]),upd(u*2+1,lz[u]),lz[u]=0;
    }return true;
}
long long query(int r,int l){
    for(ans=L=R=0,l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
        if(~l&1&&(L||lzdown(L=l^1)))ans+=arr[l^1];
        if( r&1&&(R||lzdown(R=r^1)))ans+=arr[r^1];
    }return ans;
}
void update(long long val,int r,int l){
    for(L=R=0,l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
        if(~l&1&&(L||lzdown(L=l^1)))upd(l^1,val);
        if( r&1&&(R||lzdown(R=r^1)))upd(r^1,val);
    }
    for(L/=2;L;L/=2)arr[L]=arr[L*2]+arr[L*2+1];
    for(R/=2;R;R/=2)arr[R]=arr[R*2]+arr[R*2+1];
}
/*nc*/inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
/*signed long long cinl()*/long long res,ch,flag;
long long cinl(){
    flag=(ch=nc())=='-';
    if(ch>='0'&&ch<='9')res=ch-'0';else res=0;
    while((ch=nc())>='0'&&ch<='9' )
       res=res*10+ch-'0';
    return flag?-res:res;
}
int main(){
    int n=cinl(),q=cinl();
    M=1;while(M-2<n)M*=2;
    for(int i=M+1;i<=M+n;i++)
        arr[i]=cinl(),al[i]=ar[i]=i-M;
    for(int i=M-1;i;i--)
        arr[i]=arr[i*2]+arr[i*2+1],
        al[i]=al[i*2],ar[i]=ar[i*2+1];
    while(q--){
        if(nc()=='Q')
            printf("%lld\n",query(cinl(),cinl()));
        else
            update(cinl(),cinl(),cinl());
    }
    return 0;
}