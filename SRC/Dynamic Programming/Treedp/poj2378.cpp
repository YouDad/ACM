#include<stdio.h>
#include<string.h>
const int maxn=10005;
struct edge{
    int dest;
    struct edge*next;
}e[maxn*2],*head[maxn];
int cnt,pre[maxn],nodenum[maxn],n;
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
void dfs(int rt){
    for(edge*i=head[rt];i;i=i->next){
        int v=i->dest;
        if(!pre[v]){
            pre[v]=rt;dfs(v);
            nodenum[rt]+=nodenum[v];
        }
    }nodenum[rt]++;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%d",&n)){
        memset(head,cnt=0,sizeof head);
        for(int i=0,u,v;i<n-1;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);addedge(v,u);
        }
        memset(pre,0,sizeof pre);
        memset(nodenum,0,sizeof nodenum);
        pre[1]=1;dfs(1);
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(edge*j=head[i];j;j=j->next){
                int v=j->dest;
                if(v!=pre[i]&&nodenum[v]>n/2){
                    flag=false;break;
                }
            }
            if(flag&&nodenum[i]>=n/2)
                printf("%d\n",i);
        }
    }
    return 0;
}