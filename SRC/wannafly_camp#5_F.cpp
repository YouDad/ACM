//neuqoj2110
#include<stdio.h>
long long f[61][61];
int main(){
    for(int i=1;i<=60;i++){
        for(int j=1;j<=60;j++)
            f[i][j]=f[i][j-1]+(j-1-i<0?0:f[i][j-1-i])+(j>=i);
    }
    int n,d;
    while(~scanf("%d%d",&n,&d)){
        long long ans=(1LL<<n-1)-1;
        if(d==0||n<=1)
            puts("0");
        else
            printf("%lld\n",ans-f[d][n-2]);
    }
    return 0;
}
