#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=105;
struct edge{
    int dest,dist;
    struct edge*next;
}e[maxn*2],*head[maxn];
int cnt,dist[maxn],ring[maxn];
bool inq[maxn];
void addedge(int u,int v,int w){
    e[cnt].dist=w;
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
bool spfa(int src,int n){
    memset(dist,0x3f,sizeof dist);
    memset(inq,false,sizeof inq);
    memset(ring,0,sizeof ring);
    std::queue<int>q;
    q.push(src);
    ring[src]=1;
    dist[src]=0;
    while(q.size()){
        int u=q.front(),v,w;
        q.pop();
        inq[u]=false;
        for(edge*i=head[u];i;i=i->next){
            v=i->dest;w=i->dist;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                if(!inq[v]){
                    inq[v]=true;
                    q.push(v);
                    if(++ring[v]>n)
                        return false;
                }
            }
        }
    }
    return true;
}
int main(){
    for(int n;scanf("%d",&n)&&n;){
        int m,a,b,k;
        char op[3];
        scanf("%d",&m);
        memset(head,cnt=0,sizeof head);
        for(int i=0;i<m;i++){
            scanf("%d%d%s%d",&a,&b,op,&k);
            if(op[0]=='g')
                addedge(a+b,a-1,-k-1);
            else
                addedge(a-1,a+b,k-1);
        }
        for(int i=0;i<=n;i++)
            addedge(n+1,i,0);
        if(spfa(n+1,n+1))
            puts("lamentable kingdom");
        else
            puts("successful conspiracy");
    }
    return 0;
}