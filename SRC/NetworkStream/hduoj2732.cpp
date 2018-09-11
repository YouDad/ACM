#include<stdio.h>
#include<string.h>
#include<queue>
int min(int a,int b){return a<b?a:b;}
const int maxn=805,inf=0x3f3f3f3f;
struct edge{
    int dist,dest;
    struct edge*next;
    struct edge*rev;
}e[(400*3+400*24)*2+5],*head[maxn],*last[maxn];
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
char map[25][25],map2[25][25];
struct node{
    int x,y,f,L;
}p[405];
bool valid(node&a,node&b,int d){
    int len=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return d*d>=len;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    for(int kase=1;t--;kase++){
        int n,m,c=0,d;scanf("%d%d%*c",&n,&d);
        for(int i=0;i<n;i++)gets(map[i]);
        for(int i=0;i<n;i++)gets(map2[i]);
        m=strlen(map[0]);
        int supersrc=0;
        int superdest=n*m*2+1;
        memset(head,cnt=0,sizeof head);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int id=i*m+j+1;
                p[id].x=i;
                p[id].y=j;
                p[id].f=map[i][j]-'0';
                p[id].L=map2[i][j]=='L';
            }
        }
        for(int i=1;i<=n*m;i++){
            if(p[i].f){
                addedge(2*i-1,2*i,p[i].f);
                if(p[i].L)
                    addedge(supersrc,2*i-1,1),c++;
                if(p[i].x<d||p[i].x+d>=n||p[i].y<d||p[i].y+d>=m)
                    addedge(2*i,superdest,inf);
                for(int j=1;j<=n*m;j++){
                    if(i==j||p[j].f==0)continue;
                    if(valid(p[i],p[j],d))
                        addedge(2*i,2*j-1,inf);
                }
            }
        }
        nodenum=n*m*2+2;
        printf("Case #%d: ",kase);
        int ans=c-isap(supersrc,superdest);
        if(ans>1)
            printf("%d lizards were left behind.\n",ans);
        else
            printf("%s lizard was left behind.\n",ans==1?"1":"no");
    }
    return 0;
}