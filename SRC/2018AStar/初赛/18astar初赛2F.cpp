#include<stdio.h>
#define min4(a,b,c,d) min(min(a,b),min(c,d))
int min(int a,int b){return a<b?a:b;}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int mx,my,n,x,y;
        scanf("%d%d%d",&mx,&my,&n);
        long long ans=0;
        for(int i=0;i<n;i++)
            scanf("%d%d",&x,&y),
            ans+=min4(x,y,mx-x,my-y);
        printf("%I64d\n",ans);
    }
    return 0;
}