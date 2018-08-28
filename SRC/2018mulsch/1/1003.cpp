#include<stdio.h>
#include<algorithm>
struct point{int x,y,i;}p[3005];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n*3;i++)
            scanf("%d%d",&p[i].x,&p[i].y),p[i].i=i;
        std::sort(p+1,p+1+n*3,[](point a,point b){return a.x<b.x;});
        for(int i=0;i<n;i++)
            printf("%d %d %d\n",p[i*3+1].i,p[i*3+2].i,p[i*3+3].i);
    }
    return 0;
}