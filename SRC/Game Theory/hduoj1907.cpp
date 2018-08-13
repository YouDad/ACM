/*Nim游戏 T2,S0必败*/
#include<stdio.h>
const char b[]="Brother",j[]="John";
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int nim=0,rich=0,n,ai;
        scanf("%d",&n);
        while(n--)
            scanf("%d",&ai),
            nim^=ai,
            rich+=ai>=2;
        if(nim)
            puts(rich==0?b:j);
        else
            puts(rich>=2?b:j);
    }
    return 0;
}