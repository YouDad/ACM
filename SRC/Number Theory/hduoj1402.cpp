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
    complex_t operator-()const{return complex_t(-r,-i);}
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
const int maxm=5e4+5;//< 1<<16
char a[maxm],b[maxm];
int num[maxm*2];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(gets(a)!=gets(b)){
        int alen=strlen(a),blen=strlen(b);
        int len=alen>blen?alen:blen;len++;
        int M=1;while(M<2*len)M*=2;init(M);
        memset(f,0,sizeof f);memset(g,0,sizeof g);
        for(int i=0;i<alen;i++)f[alen-1-i]=a[i]-'0';
        for(int i=0;i<blen;i++)g[blen-1-i]=b[i]-'0';
        transform(M,f,DFT);transform(M,g,DFT);
        for(int i=0;i<M;i++)f[i]*=g[i];
        transform(M,f,IDFT);memset(num,0,sizeof num);
        num[0]=f[0].r/M+0.5;
        for(int i=0;i<alen+blen;i++)
            num[i+1]=f[i+1].r/M+0.5+num[i]/10,num[i]%=10;
        int i=alen+blen;while(num[i]==0&&i>0)i--;
        while(~i)printf("%d",num[i--]);putchar('\n');
    }
    return 0;
}