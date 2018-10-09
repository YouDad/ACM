#include<stdio.h>
#include<string.h>
#include<set>
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
int dist[maxn];//hamming
typedef long long ll;
ll hash[100005];
const int seed=3;
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int k,kase=1;
    while(~scanf("%d%*c",&k)&&k!=-1){
        printf("Case %d: ",kase++);
        gets(a);gets(b);
        int la=strlen(a),lb=strlen(b);
        if(la<lb){puts("0");continue;}
        int len=la>lb?la:lb;len++;
        int M=1;while(M<2*len)M*=2;
        init(M);std::reverse(b,b+lb);
        memset(dist,0,sizeof dist);
        memset(f,0,sizeof f);memset(g,0,sizeof g);
        for(int i=0;i<la;i++)f[i]=a[i]=='a';
        for(int i=0;i<lb;i++)g[i]=b[i]=='b';
        transform(M,f,DFT);transform(M,g,DFT);
        for(int i=0;i<M;i++)f[i]*=g[i];
        transform(M,f,IDFT);
        for(int i=0;i<M;i++)dist[i]+=f[i].r/M+0.5;
        memset(f,0,sizeof f);memset(g,0,sizeof g);
        for(int i=0;i<la;i++)f[i]=a[i]=='b';
        for(int i=0;i<lb;i++)g[i]=b[i]=='a';
        transform(M,f,DFT);transform(M,g,DFT);
        for(int i=0;i<M;i++)f[i]*=g[i];
        transform(M,f,IDFT);
        for(int i=0;i<M;i++)dist[i]+=f[i].r/M+0.5;
        ll indent=1,base=seed,index=lb;
        while(index){
            if(index&1)indent*=base;
            base*=base;index/=2;
        }std::set<ll>set;
        for(int i=1;i<=la;i++)
            hash[i]=hash[i-1]*3+a[i-1]-'a'+1;
        int ans=0;
        for(int i=lb-1;i<la;i++){
            if(dist[i]<=k){
                ll hashstring=hash[i+1]-hash[i+1-lb]*indent;
                if(set.count(hashstring))continue;
                set.insert(hashstring);ans++;
            }
        }printf("%d\n",ans);
    }
    return 0;
}