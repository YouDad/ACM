#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=105;
const int maxm=3005;
const int inf=0x3f3f3f3f;
struct edge{
    int dest,cap,cost;
    struct edge*next,*rev;
}e[maxm],*head[maxn];
int dist[maxn],cnt;
bool vis[maxm],work[maxm];
void add(int u,int v,int r,int w)
{
    e[cnt].next=head[u],e[cnt].dest=v,e[cnt].cap=r;
    e[cnt].cost=w,e[cnt].rev=e+cnt+1,head[u]=e+cnt++;
    e[cnt].next=head[v],e[cnt].dest=u,e[cnt].cap=0;
    e[cnt].cost=-w,e[cnt].rev=e+cnt-1,head[v]=e+cnt++;
}
bool spfa(int src,int des)
{
    std::queue<int>q;
    memset(dist,inf,sizeof(dist));
    memset(work,false,sizeof(work));
    q.push(src),dist[src]=0;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=false;
        for(edge*i=head[u];i;i=i->next){
            int v=i->dest;
            if(i->cap&&dist[v]>dist[u]+i->cost){
                dist[v]=dist[u]+i->cost;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    return dist[des]<inf;
}
int dinic(int src,int des,int flow,int&ans)
{
    if(src==des){
        ans+=flow*dist[des];
        return flow;
    }
    work[src]=true;
    int res=0;
    for(edge*i=head[src];i;i=i->next){
        int v=i->dest;
        if(!work[v]&&i->cap&&dist[v]==dist[src]+i->cost){
            int temp=dinic(v,des,std::min(i->cap,flow-res),ans);
            if(temp){
                i->cap-=temp;
                i->rev->cap+=temp;
                res+=temp;
                if(res==flow)break;
            }
        }
    }
    return res;
}
void mcmf(int src,int des,int&flow,int&cost)
{
    cost=0;flow=0;
    while(spfa(src,des))
        flow+=dinic(src,des,inf,cost);
}
int main(){
    //freopen("1.txt","r",stdin);
    int a,b,n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(head,0,sizeof head);cnt=0;
        for(int i=1;i<=n;i++)        //init to candle
            add(0,i,1,0);
        for(int i=1;i<=n;i++)        //candle to zone
            scanf("%d%d",&a,&b),
            add(i,a+50,1,0),
            add(i,b+50,1,0);
        for(int i=0;i<n/2+1;i++)     //zone to finish
            for(int j=1;j<=m;j++)
                add(j+50,101,1,i*2+1);
        int flow,cost;
        mcmf(0,101,flow,cost);
        printf("%d\n",cost);
    }
    return 0;
}
/*
3 3
1 2
1 2
1 2

5
*/