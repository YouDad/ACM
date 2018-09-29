#include<stdio.h>
#include<cmath>
using namespace std;
typedef long double ld;
const ld pi=3.1415926535897932384626433;
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    long long n,l,r;
    scanf("%lld%lld%lld",&n,&l,&r);
    ld d=l*cos(pi/n);
    if(r<=d+1e-8)printf("%.2Lf\n",n*l*d*sin(pi/n));
    else if(r>=l)printf("%.2Lf\n",r*r*pi);
    else
        printf("%.2Lf\n",n*(
            +d*(l*sin(pi/n)-sqrt(1.0*r*r-d*d))
            +r*acos(d/r)*r
        ));
    return 0;
}