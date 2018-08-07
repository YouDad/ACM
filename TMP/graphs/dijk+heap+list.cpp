//堆优化的迪杰斯特拉,对象:链式前向星
#include<queue>
#include<memory.h>
#define maxn 100005
#define maxm 200005
#define type type
struct edge
{
    int dest;
    type dist;
    struct edge*next;
}e[maxm],*head[maxn];
int cnt;
inline void addedge(int u,int v,type w){
    e[cnt].next=head[u];
    e[cnt].dist=w;
    e[cnt].dest=v;
    head[u]=e+cnt++;
}
struct qnode
{
    int id;type dist;
    qnode(int i,type d){id=i,dist=d;}
    bool operator<(const struct qnode r)const{return dist>r.dist;}
};
bool vis[maxn];
type dist[maxn];
void dijkstra(int src,int n)
{
    memset(vis,false,sizeof vis);
    memset(dist,0x3f,sizeof dist);  ///inf
    std::priority_queue<struct qnode>q;
    dist[src]=0;q.push(qnode(src,0));
    while(q.size()){
        int u=q.top().id;
        type d=q.top().dist;q.pop();
        if(dist[u]!=d)continue;
        vis[u]=true;
        for(struct edge*ptr=head[u];ptr;ptr=ptr->next){
            int v=ptr->dest;
            if(vis[v])continue;
            type w=ptr->dist;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push(qnode(v,dist[v]));
            }
        }
    }
}

#include<bits/stdc++.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(head,0,sizeof head);
        cnt=0;
        int n,m,u,v,w;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&u,&v,&w),
            addedge(u,v,w);
        dijkstra(1,n);
        printf("%lld\n",dist[n]);
    }
    return 0;
}