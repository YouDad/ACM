#include<stdio.h>
#include<string.h>
int degree[1005],pre[1005];
int find(int x){return x==pre[x]?x:pre[x]=find(pre[x]);}
int main(){
    for(int n;scanf("%d",&n)&&n;){
        int m;scanf("%d",&m);
        memset(degree,0,sizeof degree);
        for(int i=0;i<=n;i++)
            pre[i]=i;
        for(int u,v;m--;){
            scanf("%d%d",&u,&v);
            degree[u]++;
            degree[v]++;
            pre[find(u)]=pre[find(v)];
        }
        int ans=1;
        for(int i=0;i<=n;i++)
            if(degree[i]%2){
                ans=0;
                break;
            }
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(pre[i]==i)
                cnt++;
        if(cnt!=1)
            ans=0;
        printf("%d\n",ans);
    }
    return 0;
}