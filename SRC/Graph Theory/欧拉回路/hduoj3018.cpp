#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=100005;
struct edge{
    int dest;
    struct edge*next;
}e[maxn*4],*head[maxn];
int cnt,pre[maxn],vis[maxn],degree[maxn];
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    e[cnt].dest=u;
    e[cnt].next=head[v];
    head[v]=e+cnt++;
    degree[u]++;
    degree[v]++;
}
void dfs(int u){
    vis[u]=true;
    if(degree[u]%2)cnt++;
    for(edge*i=head[u];i;i=i->next){
        if(!vis[i->dest])
            dfs(i->dest);
    }
}
int find(int x){return x==pre[x]?x:pre[x]=find(pre[x]);}
int main(){
    for(int n,m;~scanf("%d%d",&n,&m);){
        memset(head,cnt=0,sizeof head);
        memset(degree,0,sizeof degree);
        memset(vis,false,sizeof vis);
        for(int i=1;i<=n;i++)
            pre[i]=i;
        for(int u,v;m--;){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            pre[find(u)]=pre[find(v)];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(pre[i]==i&&degree[i]){
                cnt=0;
                dfs(i);
                if(cnt==0)
                    ans++;
                else
                    ans+=cnt/2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}