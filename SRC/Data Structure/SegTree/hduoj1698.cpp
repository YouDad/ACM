#include<stdio.h>
#include<string.h>
typedef int Array[(1<<18)+2];
Array al,ar,arr,lz;
int M,ss[30],top,ans,L,R;
#define upd(pos,lazy) arr[pos]=lazy*(ar[pos]-al[pos]+1),lz[pos]=lazy
bool lzdown(int u){
    if(u>M)u/=2;
    for(top=0;u;u/=2)ss[top++]=u;
    while(top--)
        if(lz[u=ss[top]])
            upd(u*2,lz[u]),upd(u*2+1,lz[u]),lz[u]=0;
    return true;
}
void update(int val,int r,int l){
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
/*cini*/int ch,res;
int cini(){
    while((ch=nc())<'0'||ch>'9');res=ch-'0';
    while((ch=nc())>='0'&&ch<='9')res=res*10+ch-'0';
    return res;
}
int main(){
    int T=cini();
    for(int kase=1;kase<=T;kase++){
        int n=cini(),q=cini(),l,r,val;
        M=1;while(M-2<n)M*=2;
        memset(lz,0,sizeof lz);
        for(int i=M+1;i<=M+n;i++)
            arr[i]=1,al[i]=ar[i]=i-M;
        for(int i=M;i;i--)
            arr[i]=arr[i*2]+arr[i*2+1],
            al[i]=al[i*2],ar[i]=ar[i*2+1];
        while(q--)
            update(cini(),cini(),cini());
        printf("Case %d: The total value of the hook is %d.\n",kase,arr[1]);
    }
    return 0;
}