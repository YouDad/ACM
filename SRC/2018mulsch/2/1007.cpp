#include<stdio.h>
#include<string.h>
typedef int Array[1<<18];
Array a,c,lz,al,ar;
int b[100005],ss[30],top,M;
#define upd(pos,lazy) c[pos]-=lazy,lz[pos]+=lazy
void down(int pos){
    if(lz[pos])
        upd(pos*2,lz[pos]),upd(pos*2+1,lz[pos]),lz[pos]=0;
}
bool lzdown(int u){
    if(u>M)u/=2;for(top=0;u;u/=2)ss[top++]=u;
    while(top--)down(ss[top]);return true;
}
int min(int a,int b){return a<b?a:b;}
int main(){
    for(int n,q;~scanf("%d%d",&n,&q);){
        int l,r,x,L,R;M=1;while(M-2<n)M*=2;
        memset(a,0,sizeof a);memset(c,0x3f,sizeof c);
        for(int i=1;i<=n;i++)scanf("%d",b+i);
        memset(lz,0,sizeof lz);memcpy(c+M+1,b+1,n<<2);
        for(int i=M-1;i;i--)c[i]=min(c[i*2],c[i*2+1]);
        for(char s[6];q--;){
            scanf("%s %d %d",s,&l,&r);
            if(s[0]=='a'){
                for(L=R=0,l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
                    if(~l&1&&(L||lzdown(L=l^1)))upd(l^1,1);
                    if( r&1&&(R||lzdown(R=r^1)))upd(r^1,1);
                }
                for(L/=2;L;L/=2)c[L]=min(c[L*2],c[L*2+1]);
                for(R/=2;R;R/=2)c[R]=min(c[R*2],c[R*2+1]);
                while(c[1]==0){
                    for(x=1;x<M;)down(x),x=x*2+(c[x*2]!=0);
                    for(c[x]=b[x-M],a[x]++,x/=2;x;x/=2)
                        c[x]=min(c[x*2],c[x*2+1]),a[x]++;
                }
            }else{
                for(x=0,l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
                    if(~l&1)x+=a[l^1];if( r&1)x+=a[r^1];
                }printf("%d\n",x);
            }
        }
    }
    return 0;
}