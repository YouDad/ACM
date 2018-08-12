#include<stdio.h>
int main(){
    for(int m,n;~scanf("%d%d",&m,&n);)
        if(m>n)
            if(m%(n+1)==0)
                puts("none");
            else
                printf("%d\n",m%(n+1));
        else
            for(int i=m;i<=n;i++)
                printf("%d%c",i,i==n?'\n':' ');
    return 0;
}