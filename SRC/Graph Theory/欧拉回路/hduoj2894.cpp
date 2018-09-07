#include<stdio.h>
#include<string.h>
const int maxn=1<<11;
bool vis[maxn];
int ss[maxn],top,n;
void dfs(int u){u=u*2%n;
    for(int v=u;v<=u+1;v++){
        if(!vis[v]){
            vis[v]=true;
            dfs(v);
            ss[top++]=v-u;
        }
    }
}
int main(){
    for(int k;~scanf("%d",&k);){
        n=1<<k;
        memset(vis,top=0,sizeof vis);
        dfs(0);
        printf("%d ",n);
        for(int i=0;i<k-1;i++)
            putchar('0');
        while(top-->k-1)
            printf("%d",ss[top]);
        putchar('\n');
    }
    return 0;
}