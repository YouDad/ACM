#include<queue>
#include<cstring>
#define eachEdge(head,from) for(int i=head[from];i!=-1;i=e[i].next)
#define type int
#define maxn 1
#define maxm 1
#define inf 1
struct edge{
    int to,next;
    type c,f,cost;
    void set(int t,int n,int cap,int flow,int c){
        to=t;
        next=n;
        this->c=cap;
        f=flow;
        cost=c;
    }
    type remind(){
        return c-f;
    }
}e[maxm];
int head[maxn],pre[maxn];
int edgeNum;
type dis[maxn];
bool vis[maxn];
void init(){
    std::memset(head,-1,sizeof(head));
    edgeNum=0;
}
void add(int u,int v,type cap,type cost){
    e[edgeNum].set(v,head[u],cap,0,cost),head[u]=edgeNum++;
    e[edgeNum].set(u,head[v],0,0,-cost),head[v]=edgeNum++;
}
bool spfa(int s,int t,int n){
    std::queue<int>q;
    std::memset(dis,inf,sizeof(dis));
    std::memset(vis,false,sizeof(vis));
    std::memset(pre,-1,sizeof(pre));
    dis[s]=0;
    vis[s]=true;
    q.push(s);
    while(q.size()){
        int u=q.front();q.pop();
        vis[u]=false;
        eachEdge(head,u){
            int v=e[i].to;
            if(e[i].remind()&&dis[v]>dis[u]+e[i].cost){
                dis[v]=dis[u]+e[i].cost;
                pre[v]=i;
                if(!vis[v])
                    vis[v]=true,q.push(v);
            }
        }
    }
    return pre[t]!=-1;
}
int mcmf(int s,int t,int n,type&cost){
    type flow=0;
    cost=0;
    while(spfa(s,t,n)){
        type Min=inf;
        for(int i=pre[t];i!=-1;i=pre[e[i^1].to])
            if(Min>e[i].remind())
                Min=e[i].remind();
        for(int i=pre[t];i!=-1;i=pre[e[i^1].to])
            e[i].f+=Min,
            e[i^1].f-=Min,
            cost+=e[i].cost*Min;
        flow+=Min;
    }
    return flow;
}