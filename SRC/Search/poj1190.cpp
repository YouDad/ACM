#include<stdio.h>
#include<string.h>
#include<math.h>
const int inf=0x3f3f3f3f;
int best,V,M,mins[21], minv[21];
void dfs(int v,int m,int lastr,int lasth,int sums){
    if(m==0&&v==0&&best>sums)best=sums;//获得更优解
    if(m==0||mins[m]+sums>=best||v<minv[m])return;//极限面积和体积
    for(int r=lastr-1;r>=m;r--){
        for(int h=lasth-1;h>=m;h--){
            int curv=r*r*h;
            if(curv<v/m)break;//底下的蛋糕体积一定比顶上的大
            if(curv>v)continue;//剩余体积不够
            int maxv=0;//剩余层数蛋糕最大需要体积
            for(int i=1;i<m;i++)
                maxv+=(r-i)*(r-i)*(h-i);
            if(v-curv>maxv)break;//剩余体积太多
            if(m==M)sums=r*r;//处理上表面的面积
            dfs(v-curv,m-1,r,h,sums+2*r*h);
        }
    }
}
int main(){
    for(int i=1;i<=20;i++)
        mins[i]=i*(i+1)*(2*i-1)/3,//完成1~i层获得的最小面积
        minv[i]=i*i*(i+1)*(i+1)/4;//完成1~i层需要的最小体积
    scanf("%d%d",&V,&M);best=inf;
    dfs(V,M,sqrt(1.0*V)+1e-4+1,V+1,0);
    printf("%d\n",best<inf?best:0);
    return 0;
}