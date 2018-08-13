//neuqoj2112
#include<stdio.h>
int main(){
    int t,n,m,k;scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        scanf("%d%d%d",&n,&m,&k);
        double ans=0;
        while(k--)ans+=1.0*n--/m--;
        printf("Case #%d: %.8lf\n",kase,ans);
    }
    return 0;
}
