#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
struct complex_t{
    double r,i;
    complex_t(){}
    complex_t(double r,double i):r(r),i(i){}
    complex_t&operator=(double x){
        r=x,i=0;
        return *this;
    }
    complex_t conj(){return complex_t(r,-i);}
    #define ops(ref,op,isconst) complex_t ref operator op(const complex_t&other)isconst
    ops(,+,const){return complex_t(r+other.r,i+other.i);}
    ops(,-,const){return complex_t(r-other.r,i-other.i);}
    ops(,*,const){return complex_t(r*other.r-i*other.i,r*other.i+i*other.r);}
    ops(&,+=,){*this=*this+other;return *this;}
    ops(&,-=,){*this=*this-other;return *this;}
    ops(&,*=,){*this=*this*other;return *this;}
};
const int maxn=1<<17;
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
        IDFT[i]=DFT[i].conj();
}
int x[50005],y[50005];
inline void selmin(int&a,int b){if(a>b)a=b;}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",x+i);
    for(int i=0;i<n;i++)scanf("%d",y+i);
    for(int i=0;i<n;i++)f[n-1-i]=x[i];
    for(int i=0;i<n;i++)g[i+n]=g[i]=y[i];
    int M=1;while(M<2*n+2)M*=2;init(M);
    transform(M,f,DFT);transform(M,g,DFT);
    for(int i=0;i<M;i++)f[i]*=g[i];
    transform(M,f,IDFT);
    int Ans=0x3f3f3f3f;
    for(int i=0;i<n;i++)
        selmin(Ans,-2*(int(f[i+n-1].r/M+0.5)));
    for(int i=0;i<n;i++)
        Ans+=x[i]*x[i]+y[i]*y[i];
    int x_y=0,Min=0x3f3f3f3f;
    for(int i=0;i<n;i++)x_y+=x[i]-y[i];
    for(int C=-m;C<=m;C++)
        selmin(Min,C*(C*n+2*x_y));
    printf("%d\n",Ans+Min);
    return 0;
}