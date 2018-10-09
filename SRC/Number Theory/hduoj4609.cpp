#include<stdio.h>
#include<string.h>
#include<math.h>
#include<complex>
#include<algorithm>
const int maxn=1<<18;
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
int a[100005],c[100005];
long long ans[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        memset(c,0,sizeof c);
        for(int i=0;i<n;i++)
            scanf("%d",a+i),c[a[i]]++;
        std::sort(a,a+n);
        int M=1;while(M<2*a[n-1]+2)M*=2;
        memset(f,0,sizeof f);
        for(int i=0;i<n;i++)
            f[a[i]]=c[a[i]];
        init(M);transform(M,f,DFT);
        for(int i=0;i<M;i++)f[i]*=f[i];
        transform(M,f,IDFT);
        for(int i=0;i<M;i++)
            ans[i]=f[i].real()/M+0.5;
        for(int i=0;i<n;i++)
            ans[a[i]*2]--;
        for(int i=1;i<M;i++)
            ans[i]=ans[i]/2+ans[i-1];
        long long cnt=0;
        for(long long i=0;i<n;i++){
            cnt+=ans[M-1]-ans[a[i]];
            cnt-=i*(n-1-i);
            cnt-=n-1;
            cnt-=(n-1-i)*(n-2-i)/2;
        }
        printf("%.7lf\n",6.0*cnt/n/(n-1)/(n-2));
    }
    return 0;
}