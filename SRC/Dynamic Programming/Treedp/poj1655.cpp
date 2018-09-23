#include<stdio.h>
#include<string.h>
const int maxn=20005;
struct edge{
    int dest;
    edge*next;
}e[maxn*2],*head[maxn];
int cnt;
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
int sz[maxn];//nodenum
int min,minid,n;
void dfs(int u,int f){
    sz[u]=1;int max=0;
    for(edge*i=head[u];i;i=i->next){
        int v=i->dest;if(v==f)continue;
        dfs(v,u);sz[u]+=sz[v];
        if(max<sz[v])max=sz[v];
    }
    if(n-sz[u]>max)max=n-sz[u];
    if(max==min&&minid>u)minid=u;
    if(min>max)min=max,minid=u;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        memset(head,cnt=0,sizeof head);
        scanf("%d",&n);
        for(int i=1,u,v;i<n;i++)
            scanf("%d%d",&u,&v),
            addedge(u,v),addedge(v,u);
        min=0x3f3f3f3f;dfs(1,0);
        printf("%d %d\n",minid,min);
    }
    return 0;
}