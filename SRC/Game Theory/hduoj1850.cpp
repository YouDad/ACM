//思路:Nim游戏必胜态为sumxor!=0
//但是题目求第一步方案数
//考虑Nim游戏最优策略(必胜态)为
//先手必胜态想办法转移到必败态
//也就是减少某堆数量使得sumxor==0
#include<stdio.h>
int a[105];
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        int nim=0,ans=0;
        for(int i=0;i<n;i++)
            scanf("%d",a+i),nim^=a[i];
        for(int i=0;i<n;i++)
            ans+=a[i]>(nim^a[i]);
        printf("%d\n",ans);
    }
    return 0;
}