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
const int maxn=1<<18;
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
const int maxm=125005;
char a[maxm],b[maxm];
int pre[maxm][6],alen,blen,M,stat[maxm];
void statfunc(char A,char B){
    memset(f,0,sizeof f);memset(g,0,sizeof g);
    for(int i=0;i<alen;i++)f[i]=a[i]==A;
    for(int i=0;i<blen;i++)g[i]=b[i]==B;
    transform(M,f,DFT);transform(M,g,DFT);
    for(int i=0;i<M;i++)f[i]*=g[i];
    transform(M,f,IDFT);
    for(int i=0;i<alen-blen+1;i++)
        stat[i]=f[i+blen-1].r/M+0.5;
}
int find(int k,int x){
    if(pre[k][x]==x)return x;
    return pre[k][x]=find(k,pre[k][x]);
}
void join(int k,int x,int y){
    int fx=find(k,x),fy=find(k,y);
    if(fy>fx)fx^=fy^=fx^=fy;
    pre[k][fx]=pre[k][fy];
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    gets(a);gets(b);
    alen=strlen(a);blen=strlen(b);
    std::reverse(b,b+blen);
    M=1;while(M<2*alen+2)M*=2;init(M);
    for(int i=0;i<alen-blen+1;i++)
    for(int j=0;j<=5;j++)pre[i][j]=j;
    for(int i=0;i<=5;i++)
    for(int j=0;j<=5;j++){
        if(i==j)continue;
        statfunc(i+'a',j+'a');
        for(int k=0;k<alen-blen+1;k++)
            if(stat[k])join(k,i,j);
    }
    for(int i=0;i<alen-blen+1;i++){
        int cnt=0;
        for(int j=0;j<=5;j++)
            cnt+=pre[i][j]!=j;
        printf("%d%c",cnt," \n"[i==alen-blen]);
    }
    return 0;
}