#include<stdio.h>
#include<string.h>
#include<math.h>
#include<complex>
#include<algorithm>
const int maxn=1<<19;
typedef std::complex<double>complex_t;
complex_t f[maxn];
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
    int n;
    while(~scanf("%d",&n)){
        memset(f,0,sizeof f);
        int t,M=1;
        while(n--){
            scanf("%d",&t);f[t]=1;
            while(M<t*2)M*=2;
        }init(M);f[0]=1;
        transform(M,f,DFT);
        for(int i=0;i<M;i++)f[i]*=f[i];
        transform(M,f,IDFT);
        scanf("%d",&n);int ans=0;
        while(n--){
            scanf("%d",&t);
            ans+=(f[t].real()>=M/2);
        }printf("%d\n",ans);
    }
    return 0;
}