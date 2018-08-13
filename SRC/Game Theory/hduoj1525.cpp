#include<stdio.h>
bool dfs(int x,int y){
    if(x>y){int t=x;x=y;y=t;}
    if(y%x==0||y>=2*x)return true;
    return !dfs(y%x,x);
}
int main(){
    for(int a,b;scanf("%d%d",&a,&b)&&a+b;)
        puts(dfs(a,b)?"Stan wins":"Ollie wins");
    return 0;
}