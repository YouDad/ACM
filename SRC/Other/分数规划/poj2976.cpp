#include<stdio.h>
#include<algorithm>
int a[1005],b[1005],n,k;
double c[1005];
bool check(double mid){
    for(int i=0;i<n;i++)
        c[i]=a[i]-mid*b[i];
    std::sort(c,c+n);
    double sum=0;
    for(int i=k;i<n;i++)
        sum+=c[i];
    return sum>=0;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&k)&&n+k){
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)scanf("%d",b+i);
        double L=0,R=1,ans=0;
        while(L+1e-4<=R){
            double mid=(L+R)/2;
            if(check(mid))
                L=mid,ans=mid;
            else R=mid;
        }printf("%.lf\n",ans*100);
    }
    return 0;
}