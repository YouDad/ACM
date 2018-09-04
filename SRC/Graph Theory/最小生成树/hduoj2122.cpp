#include<stdio.h>
#include<queue>
int pre[1005];
int find(int x){
    return pre[x]==x?x:pre[x]=find(pre[x]);
}
struct edge{
    int u,v,w;
    edge(int a=0,int b=0,int c=0){
        u=a;v=b;w=c;
    }
    bool operator<(const edge other)const{
        return w>other.w;
    }
};
int main(){
    for(int n,m;~scanf("%d%d",&n,&m);){
        int u,v,c,cost=0;
        for(int i=0;i<=n;i++)pre[i]=i;
        std::priority_queue<edge>q;
        while(m--)
            scanf("%d%d%d",&u,&v,&c),
            q.push(edge(u,v,c));
        for(m=1;m!=n&&q.size();){
            edge e=q.top();q.pop();
            if(find(e.u)!=find(e.v))
                cost+=e.w,pre[find(e.u)]=find(e.v),m++;
        }
        if(m!=n)puts("impossible");
        else printf("%d\n",cost);
        putchar('\n');
    }
    return 0;
}