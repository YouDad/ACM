#include<stdio.h>
#include<string.h>
#include<queue>
struct edge{
    int dest,dist,cost;
    struct edge*next;
}e[200005],*head[1005];
int cnt,dist[1005],cost[1005];
bool vis[1005];
void addedge(int u,int v,int w,int c){
    e[cnt].dest=v;
    e[cnt].dist=w;
    e[cnt].cost=c;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
struct qnode{
    int id,dist,cost;
    qnode(int i=0,int d=0,int c=0){
        id=i;dist=d;cost=c;
    }
    bool operator<(const qnode&other)const{
        return dist>other.dist;
    }
};
void dijkstra(int src){
    memset(vis,false,sizeof vis);
    memset(dist,0x3f,sizeof dist);
    memset(cost,0x3f,sizeof cost);
    std::priority_queue<qnode>q;
    q.push(qnode(src,dist[src]=0,cost[src]=0));
    while(q.size()){
        int u,v,d,c;
        u=q.top().id;
        d=q.top().dist;
        c=q.top().cost;
        q.pop();
        if(dist[u]!=d)continue;
        vis[u]=true;
        for(edge*i=head[u];i;i=i->next){
            v=i->dest;
            if(vis[v])continue;
            d=i->dist;
            c=i->cost;
            if(dist[v]>dist[u]+d){
                dist[v]=dist[u]+d;
                cost[v]=cost[u]+c;
                q.push(qnode(v,dist[v],cost[v]));
            }else if(dist[v]==dist[u]+d){
                if(cost[v]>cost[u]+c)
                    cost[v]=cost[u]+c;
            }
        }
    }
}
int main(){
    for(int n,m;scanf("%d%d",&n,&m)&&n+m;){
        int u,v,d,c;
        memset(head,cnt=0,sizeof head);
        while(m--)
            scanf("%d%d%d%d",&u,&v,&d,&c),
            addedge(u,v,d,c),addedge(v,u,d,c);
        int src,dest;
        scanf("%d%d",&src,&dest);
        dijkstra(src);
        printf("%d %d\n",dist[dest],cost[dest]);
    }
    return 0;
}