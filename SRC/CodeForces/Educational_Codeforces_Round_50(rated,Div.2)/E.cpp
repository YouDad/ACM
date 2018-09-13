#include<stdio.h>
#include<utility>
#include<set>
const double eps=1e-8;
typedef long long ll;
typedef std::pair<ll,ll> pll;
struct segment{
    int x,y,dx,dy;
    segment(ll x0=0,ll y0=0,ll x1=0,ll y1=0){
        x=x0;y=y0;dx=x1-x0;dy=y1-y0;
    }
}seg[1005];
bool intersect(segment&a,segment&b,ll&xx,ll&yy){
    ll dx1=a.dx,dx2=b.dx;
    ll dy1=a.dy,dy2=b.dy;
    ll qq=dy2*dx1-dx2*dy1;
    if(qq==0)return false;
    ll x1=a.x,x2=b.x;
    ll y1=a.y,y2=b.y;
    ll pp1=(x2-x1)*dy2+(y1-y2)*dx2;
    if(pp1*dx1%qq)return false;
    if(pp1*dy1%qq)return false;
    ll pp2=(x2-x1)*dy1+(y1-y2)*dx1;
    double rr1=(double)pp1/qq;
    if(rr1<=-eps||rr1>=1+eps)return false;
    double rr2=(double)pp2/qq;
    if(rr2<=-eps||rr2>=1+eps)return false;
    xx=pp1*dx1/qq+x1;
    yy=pp1*dy1/qq+y1;
    return true;
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int abs(int a){
    return a<0?-a:a;
}
std::set<pll>s;
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    ll x,y;
    int n,ans=0,x0,y0,x1,y1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
        seg[i]=segment(x0,y0,x1,y1);
    }
    for(int i=0;i<n;i++){
        s.clear();
        ans+=gcd(abs(seg[i].dx),abs(seg[i].dy))+1;
        for(int j=0;j<i;j++){
            if(intersect(seg[i],seg[j],x,y)){
                pll p=std::make_pair(x,y);
                if(!s.count(p)){
                    s.insert(p),ans--;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}