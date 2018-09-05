#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=1005;
struct edge{
    int dest,dist;
    struct edge*next;
}e[maxn*2],*head[maxn];
int cnt,dist[maxn];
bool vis[maxn];
void addedge(int u,int v,int w){
    e[cnt].dest=v;
    e[cnt].dist=w;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
struct qnode{
    int id,dist;
    qnode(int i=0,int d=0){
        id=i;dist=d;
    }
    bool operator<(const qnode&other)const{
        return dist>other.dist;
    }
};
void dijkstra(int src){
    memset(vis,false,sizeof vis);
    memset(dist,0x3f,sizeof dist);
    std::priority_queue<qnode>q;
    q.push(qnode(src,dist[src]=0));
    while(q.size()){
        int u,v,w;
        u=q.top().id;w=q.top().dist;q.pop();
        if(d!=dist[u])
            continue;
        vis[u]=true;
        for(edge*i=head[u];i;i=i->next){
            v=i->dest;w=i->dist;
            if(vis[v])
                continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push(qnode(v,dist[v]));
            }
        }
    }
}
int main(){
    for(int t,s,d;~scanf("%d%d%d",&t,&s,&d);){
        memset(head,cnt=0,sizeof head);
        for(int i=0,u,v,w;i<t;i++){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        for(int i=0,x;i<s;i++){
            scanf("%d",&x);
            addedge(0,x,0);
            addedge(x,0,0);
        }
        for(int i=0,x;i<d;i++){
            scanf("%d",&x);
            addedge(x,1001,0);
            addedge(1001,x,0);
        }
        dijkstra(0);
        printf("%d\n",dist[1001]);
    }
    return 0;
}