#include<stdio.h>
long long x[1005],y[1005];
long long target;
long long dis(int i,int j){
    return (x[i]-x[j])*(x[i]-x[j])+
        (y[i]-y[j])*(y[i]-y[j]);
}
bool check(int x,int n){
    for(int i=0;i<n;i++)
        if(i!=x&&dis(i,x)!=target)
            return false;
    return true;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",x+i,y+i);
    for(int i=0;i<n;i++){
        target=dis(0,i==0?1:i);
        if(check(i,n)){
            printf("%d\n",i+1);
            return 0;
        }
    }puts("-1");
    return 0;
}