#include<stdio.h>
#include<string.h>
char str[]="jessie";
char s[30];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        for(char*p=s;*p;p++)
            *p|=32;
        if(strcmp(s,str)==0)
            puts("Good guy!");
        else
            puts("Dare you say that again?");
    }
    return 0;
}