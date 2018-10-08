#include<string.h>
#include<stdio.h>
#include<math.h>
#include<complex>
#include<algorithm>
const int maxn=1<<18;
typedef std::complex<double>complex_t;
complex_t f[maxn],g[maxn];
complex_t DFT[maxn],IDFT[maxn];
const double pi=acos(-1.0);
void transform(int n,complex_t*x,complex_t*w){
    for(int i=0,j=0;i<n;i++){
        if(i>j)std::swap(x[i],x[j]);
        int t=n/2;while((j^=t)<t)t/=2;
    }
    for(int i=2;i<=n;i*=2){
        int m=i/2;
        for(int j=0;j<n;j+=i){
            for(int k=0;k<m;k++){
                complex_t z=x[j+m+k]*w[n/i*k];
                x[j+m+k]=x[j+k]-z;
                x[j+k]+=z;
            }
        }
    }
}
void init(int n){
    double angle=2.0*pi/n;
    for(int i=0;i<n;i++)
        DFT[i]=complex_t(cos(i*angle),sin(i*angle));
    for(int i=0;i<n;i++)
        IDFT[i]=conj(DFT[i]);
}
char s[50005],t[50005],o[100005];
int r[100005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%s",s)){
        scanf("%s",t);
        int sl=strlen(s),tl=strlen(t);
        int len=sl>tl?sl:tl;
        int M=1;while(M<len*2)M*=2;
        init(M);memset(f,0,sizeof f);
        memset(g,0,sizeof g);
        for(int i=0;i<M;i++)
            if(s[i])f[sl-1-i]=s[i]-'0';
        for(int i=0;i<M;i++)
            if(t[i])g[tl-1-i]=t[i]-'0';
        transform(M,f,DFT);
        transform(M,g,DFT);
        for(int i=0;i<M;i++)f[i]*=g[i];
        transform(M,f,IDFT);
        for(int i=0;i<M;i++)
            r[i+1]=f[i].real()/M+0.5+r[i]/10,r[i]%=10;
        int i=M,j=0;while(r[i]==0&&i>1)i--;
        while(i)o[j++]=r[i--]+'0';
        o[j]=0;puts(o);
    }
    return 0;
}