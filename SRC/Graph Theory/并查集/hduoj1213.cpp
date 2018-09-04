#include<stdio.h>
int pre[1005];
int find(int x){
    return pre[x]==x?x:pre[x]=find(pre[x]);
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m,u,v;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
            pre[i]=i;
        while(m--)
            scanf("%d%d",&u,&v),
            pre[find(u)]=pre[find(v)];
        for(int i=0;i<=n;i++)
            m+=(pre[i]==i);
        printf("%d\n",m);
    }
    return 0;
}