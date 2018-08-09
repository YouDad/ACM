#include<stdio.h>
const double co=1.6180339887498948482045868343656;
int abs(int x){return x<0?-x:x;}
int min(int x,int y){return x<y?x:y;}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m))
        printf("%d\n",int(abs(n-m)*co)!=min(n,m));
    return 0;
}