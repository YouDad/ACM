#include<bits/stdc++.h>
#define maxn 100005
#define maxm 200005
struct qnode
{
    int id;long long dist;
    qnode(int i,long long d){id=i,dist=d;}
    bool operator<(const struct qnode r)const{return dist>r.dist;}
};
struct edge
{
    int dest;
    long long dist;
    struct edge*next;
}e[maxm],*head[maxn];
int cnt;
bool vis[maxn];
long long dist[maxn];
void dijkstra(int src,int n)
{
    memset(vis,false,sizeof vis);
    memset(dist,0x3f,sizeof dist);  ///inf
    std::priority_queue<struct qnode>q;
    dist[src]=0;q.push(qnode(src,0));
    while(q.size()){
        int u=q.top().id;q.pop();vis[u]=true;
        for(struct edge*ptr=head[u];ptr;ptr=ptr->next){
            int v=ptr->dest;
            if(vis[v])continue;
            long long w=ptr->dist;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push(qnode(v,dist[v]));
            }
        }
    }
}
inline void addedge(int u,int v,int w){
    e[cnt].next=head[u];
    e[cnt].dist=w;
    e[cnt].dest=v;
    head[u]=e+cnt++;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(head,0,sizeof head);
        memset(dist,0x3f,sizeof dist);  ///inf
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