//neuqoj2125
#include<stdio.h>
#include<string.h>
bool isrereader[1005];
char s[105],last[105];
int main(){
    //freopen("1.txt","r",stdin);
    int n,m,t;
    while(~scanf("%d %d%*c",&n,&m)){
        memset(isrereader,true,sizeof isrereader);last[0]=0;
        while(m--){
            scanf("%d %s",&t,s);
            if(strcmp(s,last))
                isrereader[t]=false;
            strcpy(last,s);
        }
        int i=1;
        for(;i<=n;i++)
            if(isrereader[i]){
                printf("%d",i++);
                break;
            }
        for(;i<=n;i++)
            if(isrereader[i])
                printf(" %d",i);
        putchar('\n');
    }
    return 0;
}