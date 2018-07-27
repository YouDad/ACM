#include<string.h>
#define eachEdge(head,from) for(int i=head[from];i!=-1;i=e[i].next)
#define type int
#define maxn 1
#define maxm 1
#define inf 1
struct edge{
    int to,next;
    type c,f;
    void set(int t,int n,type cap,type flow){
        to=t;
        next=n;
        c=cap;
        f=flow;
    }
    type remind(){
        return c-f;
    }
}e[maxm*2];
int edgeNum;
int head[maxn],gap[maxn],dep[maxn],pre[maxn],cur[maxn];
void init(){
    edgeNum=0;
    memset(head,-1,sizeof head);
}
void add(int u,int v,type cap,type recap=0){
    e[edgeNum].set(v,head[u],cap,0),head[u]=edgeNum++;
    e[edgeNum].set(u,head[v],recap,0),head[v]=edgeNum++;
}
type sap(int start,int end,int n){
    memset(gap,0,sizeof gap);
    memset(dep,0,sizeof dep);
    memcpy(cur,head,sizeof head);
    int u=start;
    pre[u]=-1;
    gap[0]=n;
    type ans=0;
    while(dep[start]<n){
        if(u==end){
            type Min=inf;
            for(int i=pre[u];i!=-1;i=pre[e[i^1].to])
                if(Min>e[i].remind())
                    Min=e[i].remind();
            for(int i=pre[u];i!=-1;i=pre[e[i^1].to])
                e[i].f+=Min,e[i^1].f-=Min;
            u=start;
            ans+=Min;
            continue;
        }
        bool flag=false;
        int v;
        eachEdge(cur,u){
            v=e[i].to;
            if(e[i].remind()&&dep[v]+1==dep[u]){
                flag=true;
                cur[u]=pre[v]=i;
                break;
            }
        }
        if(flag){
            u=v;
        }
        int Min=n;
        eachEdge(head,u){
            if(e[i].remind()&&dep[e[i].to]<Min)
                Min=dep[e[i].to],
                cur[u]=i;
        }
        gap[dep[u]]--;
        if(!gap[dep[u]])
            return ans;
        dep[u]=Min+1;
        gap[dep[u]]++;
        if(u-start)
            u=e[pre[u]^1].to;
    }
}