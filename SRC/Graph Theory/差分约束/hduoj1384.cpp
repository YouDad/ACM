#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=50005;
struct edge{
    int dest,dist;
    struct edge*next;
}e[maxn*3],*head[maxn];
int cnt,dist[maxn],ring[maxn];
bool inq[maxn];
void addedge(int u,int v,int w){
    e[cnt].dest=v;
    e[cnt].dist=w;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
bool spfa(int src,int n){
    memset(dist,0x3f,sizeof dist);
    memset(inq,false,sizeof inq);
    memset(ring,0,sizeof ring);
    std::queue<int>q;q.push(src);dist[src]=0;
    while(q.size()){
        int u=q.front();q.pop();inq[u]=false;
        for(edge*i=head[u];i;i=i->next){
            int v=i->dest,w=i->dist;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                    if(++ring[v]>n)
                        return false;
                }
            }
        }
    }
    return true;
}
int main(){
    for(int n;~scanf("%d",&n);){
        memset(head,cnt=0,sizeof head);
        int min=maxn,max=0;
        for(int i=0,a,b,c;i<n;i++){
            scanf("%d%d%d",&a,&b,&c);
            addedge(a++,++b,-c);
            if(max<b)max=b;
            if(min>a)min=a;
        }
        for(int i=min;i<=max;i++)
            addedge(i-1,i,0),
            addedge(i,i-1,1);
        spfa(min-1,max-min+2);
        printf("%d\n",-dist[max]);
    }
}