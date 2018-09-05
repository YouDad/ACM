#include<stdio.h>
#include<string.h>
#include<queue>
#define debug //printf
struct edge{
    int dist,dest;
    struct edge*next;
}e[405],*head[205];
int cnt;
void addedge(int u,int v,int w){
    e[cnt].dest=v;
    e[cnt].dist=w;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
struct qnode{
    int id,dist;
    bool operator<(const qnode&other)const{
        return dist>other.dist;
    }
};
bool vis[205];
int dist[205];
void dijkstra(int src){
    memset(vis,false,sizeof vis);
    memset(dist,0x3f,sizeof dist);
    std::priority_queue<qnode>q;
    q.push({src,dist[src]=0});
    while(q.size()){
        int u=q.top().id,d=q.top().dist;q.pop();
        debug("visit No.%d dist=%d\n",u,d);
        if(dist[u]!=d)continue;
        vis[u]=true;
        for(edge*i=head[u];i;i=i->next){
            int v=i->dest,w=i->dist;
            debug("\tNo.%d node's next is No.%d,the edge weight is %d\n",u,v,w);
            if(!vis[v])
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({v,dist[v]});
            }
        }
    }
}
int main(){
    for(int n;scanf("%d",&n)&&n;){
        int src,dest;
        scanf("%d%d",&src,&dest);
        memset(head,cnt=0,sizeof head);
        for(int i=1,d;i<=n;i++){
            scanf("%d",&d);
            if(i-d>=1)addedge(i,i-d,1);
            if(i+d<=n)addedge(i,i+d,1);
        }dijkstra(src);
        for(int i=1;i<=n;i++)
            debug("dist[%d]:%d\n",i,dist[i]);
        if(dist[dest]==0x3f3f3f3f)puts("-1");
        else printf("%d\n",dist[dest]);
    }
    return 0;
}