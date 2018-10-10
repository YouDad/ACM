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
char a[100005],b[100005];
int stat[maxn],alen,blen,M;
void statfunc(char A,char B){
    memset(f,0,sizeof f);memset(g,0,sizeof g);
    for(int i=0;i<alen;i++)f[i]=a[i]==A;
    for(int i=0;i<blen;i++)g[i]=b[i]==B;
    transform(M,f,DFT);transform(M,g,DFT);
    for(int i=0;i<M;i++)f[i]*=g[i];
    transform(M,f,IDFT);
    for(int i=0;i<alen-blen+1;i++)
        stat[i]+=f[i+blen-1].r/M+0.5;
}
#include<set>
const int seed=3;
long long hash[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int k,kase=1;
    while(~scanf("%d%*c",&k)&&k!=-1){
        gets(a);gets(b);memset(stat,0,sizeof stat);
		alen=strlen(a);blen=strlen(b);std::reverse(b,b+blen);
        M=1;while(M<2*alen+2)M*=2;init(M);
        statfunc('a','b');statfunc('b','a');
        long long indent=1,index=blen,base=seed;
        while(index){
            if(index&1)indent*=base;
            base*=base;index/=2;
        }std::set<long long>set;
        for(int i=0;i<alen;i++)hash[i+1]=hash[i]*seed+a[i]-'a'+1;
        for(int i=0;i<alen-blen+1;i++){
            if(stat[i]>k)continue;
            long long hashstring=hash[i+blen]-hash[i]*indent;
            set.insert(hashstring);
        }printf("Case %d: %d\n",kase++,set.size());
    }
    return 0;
}