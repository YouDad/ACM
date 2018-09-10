#include<stdio.h>
#include<string.h>
#include<queue>
int min(int a,int b){return a<b?a:b;}
const int maxn=1005,inf=0x3f3f3f3f;
struct edge{
    int dist,dest;
    struct edge*next;
    struct edge*rev;
}e[(500*500+500+500)*2+5],*head[maxn],*last[maxn];
int cnt,gap[maxn],dist[maxn],nodenum;
void addedge(int u,int v,int w){
    e[cnt].dist=w;
    e[cnt].dest=v;
    e[cnt].next=head[u];
    e[cnt].rev=e+cnt+1;
    head[u]=e+cnt++;
    e[cnt].dist=0;
    e[cnt].dest=u;
    e[cnt].next=head[v];
    e[cnt].rev=e+cnt-1;
    head[v]=e+cnt++;
}
int aug(int u,int src,int dest,int mi){
    if(u==dest)
        return mi;
    int flow=0;
    for(edge*&i=last[u];i;i=i->next){
        int v=i->dest;
        if(dist[u]==dist[v]+1){
            int tmp=aug(v,src,dest,min(mi,i->dist));
            flow+=tmp;
            mi-=tmp;
            i->dist-=tmp;
            i->rev->dist+=tmp;
            if(!mi)
                return flow;
        }
    }
    if(!--gap[dist[u]])
        dist[src]=nodenum+1;
    ++gap[++dist[u]];
    last[u]=head[u];
    return flow;
}
int isap(int src,int dest){
    int u,v;
    memset(gap,0,sizeof gap);
    memset(dist,0,sizeof dist);
    memcpy(last,head,sizeof last);
    ++gap[dist[dest]=1];
    std::queue<int>q;
    q.push(dest);
    while(q.size()){
        u=q.front();q.pop();
        for(edge*i=head[u];i;i=i->next){
            v=i->dest;
            if(!dist[v]){
                dist[v]=dist[u]+1;
                gap[dist[v]]++;
                q.push(v);
            }
        }
    }
    int ret=aug(src,src,dest,inf);
    while(dist[src]<=nodenum)
        ret+=aug(src,src,dest,inf);
    return ret;
}
//初始化head cnt nodenum