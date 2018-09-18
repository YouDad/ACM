#include<stdio.h>
#include<string.h>
#include<math.h>
const int maxn=10005;
const double PI=3.14159265358979;
double x[1<<15],y[1<<15];
int lz[1<<15],da[maxn];
int M,ss[32],top;
void upd(int pos,int a){
    double angle=a*PI/180;
    double xx=x[pos]*cos(angle)-y[pos]*sin(angle);
    double yy=x[pos]*sin(angle)+y[pos]*cos(angle);
    x[pos]=xx,y[pos]=yy;lz[pos]+=a;
}
bool lzdown(int u){
    if(u>M)u/=2;
    for(top=0;u;u/=2)ss[top++]=u;
    while(top--){
        u=ss[top];
        upd(u*2,lz[u]);
        upd(u*2+1,lz[u]);
        lz[u]=0;
    }return true;
}
void update(int l,int r,int a){
    int L=0,R=0;
    for(l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
        if(~l&1)if(L||(lzdown(L=l^1)))upd(l^1,a);
        if( r&1)if(R||(lzdown(R=r^1)))upd(r^1,a);
    }
    for(L/=2;L;L/=2)
        x[L]=x[L*2]+x[L*2+1],
        y[L]=y[L*2]+y[L*2+1];
    for(R/=2;R;R/=2)
        x[R]=x[R*2]+x[R*2+1],
        y[R]=y[R*2]+y[R*2+1];
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m,first=1;
    while(~scanf("%d%d",&n,&m)){
        if(first)first=0;else puts("");
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        memset(lz,0,sizeof lz);
        for(int i=1;i<=n;i++)da[i]=180;
        M=1;while(M-2<n)M*=2;
        for(int i=1+M;i<=n+M;i++)scanf("%lf",y+i);
        for(int i=M-1;i;i--)y[i]=y[i*2]+y[i*2+1];
        int s,a;
        while(m--){
            scanf("%d%d",&s,&a);
            update(s+1,n,a-da[s]);da[s]=a;
            printf("%.2lf %.2lf\n",x[1],y[1]);
        }
    }
    return 0;
}