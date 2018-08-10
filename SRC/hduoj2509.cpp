/*Nim游戏 T2,S0必败*/
#include<stdio.h>
int main(){
    int n;
    while(~scanf("%d",&n)){
        int nim=0,rich=0,ai;
        while(n--)
            scanf("%d",&ai),
            nim^=ai,rich+=ai>=2;
        if(nim)
            puts(rich==0?"No":"Yes");
        else
            puts(rich>=2?"No":"Yes");
    }
    return 0;
}