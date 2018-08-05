//neuqoj2093
#include<stdio.h>
#include<math.h>
#include<algorithm>
int main(){
    // freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--){
        int m,k,a[20]={0},c[20],d[20],p[20]={},dp[20];
        scanf("%d%d",&m,&k);
        for(int i=1;i<=m;i++)
            scanf("%d%d",a+i,p+i);
        for(int i=1;i<=k;i++)
            scanf("%d%d",c+i,d+i);
        for(int i=0;i<=m;i++){
            int need=0;
            for(int j=1;j<=k;j++){
                int x=d[j]*(100-p[i]);
                x=(x%100?1:0)+x/100;
                need+=x*c[j];
            }
            dp[i]=std::max(need,a[i]);
        }
        int ans=*std::min_element(dp,dp+m+1);
        ans=(ans%10?1:0)+ans/10;
        printf("%d\n",ans);
    }
    return 0;
}