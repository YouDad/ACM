#include<stdio.h>
#define rep(a,b) for(int k=0;k<a;k++)putchar(b)
#define rep2(a,b,c) rep(a,b),putchar(c)
int main(){
    int t,a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        for(int i=0;i<b;i++){
            rep((b-i)*2,'.');
            putchar('+');
            rep2(a,'-','+');
            rep2(i,'.',".+"[k<c]);
            putchar('\n');
            rep((b-i)*2-1,'.');
            putchar('/');
            rep2(a,'.','/');
            putchar('|');
            rep2(i,"/."[k>=c],"|."[k>=c-1]);
            putchar('\n');
        }
        for(int i=0;i<c;i++){
            putchar('+');
            rep2(a,'-','+');
            rep2(b,'.',"+."[k+i>=c]);
            putchar('\n');
            putchar('|');
            rep2(a,'.','|');
            rep2(b,"./"[k+i<c],"|."[k+i>=c-1]);
            putchar('\n');
        }
        putchar('+');
        rep2(a,'-','+');
        rep(b*2,'.');
        putchar('\n');
    }
    return 0;
}