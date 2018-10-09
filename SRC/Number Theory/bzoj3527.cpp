#include<stdio.h>
#include<string.h>
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
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);double t;
    for(int i=0;i<n;i++)
        scanf("%lf",&t),f[i]=t;
    int M=1;while(M<2*n)M*=2;
    init(M);n--;
    for(int i=0;i<n;i++)
        g[i]=1.0/(n-i)/(n-i),g[2*n-i]=-g[i];
    std::reverse(g,g+M);
    transform(M,f,DFT);
    transform(M,g,DFT);
    for(int i=0;i<M;i++)f[i]*=g[i];
    transform(M,f,IDFT);
    for(int i=M-n-1;i<M;i++)
        printf("%lf\n",f[i].real()/M);
    return 0;
}