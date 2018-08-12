#include<stdio.h>
#include<string.h>
#include<algorithm>
int degree[200005];
int main(){
    int t,n,m,k;scanf("%d",&t);
    while(t--){
        memset(degree,0,sizeof degree);
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1,u,v;i<=m;i++)
            scanf("%d%d",&u,&v),
            degree[u]++,
            degree[v]++;
        printf("%d\n",std::min(n-1,*std::max_element(degree,degree+n)+n-1-m+k));
    }
    return 0;
}