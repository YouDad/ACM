#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
const int maxn=1005;
struct edge{
    int dist,dest;
    struct edge*next;
}e[maxn*2],*head[maxn];
int cnt,dist[maxn],ring[maxn],len[maxn];
bool inq[maxn];
void addedge(int u,int v,int w){
    e[cnt].dist=w;
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
bool spfa(int src,int n){
    memset(dist,0x3f,sizeof dist);
    memset(ring,0,sizeof ring);
    memset(inq,false,sizeof inq);
    std::queue<int>q;
    q.push(src);
    dist[src]=0;
    while(q.size()){
        int u,v,w;
        u=q.front();
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
    for(int n,kase=1;scanf("%d",&n)&&n;){
        for(int i=1;i<=n;i++)
            scanf("%d",len+i);
        int u,v,w;char op[4];
        memset(head,cnt=0,sizeof head);
        while(scanf("%s",&op)&&op[0]!='#'){
            scanf("%d%d",&u,&v);
            switch(op[0]+op[2]*256){
                case 'S'+'S'*256:w=0;break;
                case 'S'+'F'*256:w=-len[v];break;
                case 'F'+'S'*256:w=len[u];break;
                case 'F'+'F'*256:w=len[u]-len[v];break;
            }
            addedge(u,v,w);
        }
        for(int i=1;i<=n;i++)
            addedge(0,i,0);
        printf("Case %d:\n",kase++);
        if(spfa(0,n)){
            int min=*std::min_element(dist+1,dist+n+1);
            for(int i=1;i<=n;i++)
                printf("%d %d\n",i,dist[i]-min);
        }else puts("impossible");
        putchar('\n');
    }
    return 0;
}