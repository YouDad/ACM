// https://nanti.jisuanke.com/t/31462
#include<stdio.h>
#include<string.h>
#include<algorithm>
const int maxn=250005;
#define nowcoord i*n+j+1
#define rightcoord i*n+j+2
#define downcoord i*n+j+n+1
int prev[maxn];
int n,m,q,w;char op[2];
void init(){for(int i=0;i<=n*m;i++)prev[i]=i;}
int find(int x){return x==prev[x]?x:prev[x]=find(prev[x]);}
void join(int x,int y){prev[find(x)]=prev[find(y)];}
bool same(int x,int y){return find(x)==find(y);}
struct setedge{
    int u,v,w;
}e[maxn*2];
struct edge{
    int dest,dist;
    struct edge*next;
}ee[maxn*2],*head[maxn];
int cnt,knt;
void addsetedge(int u,int v,int w){
    e[cnt].u=u;e[cnt].v=v;e[cnt++].w=w;
}
void addedge(setedge&x){
    ee[knt].dest=x.v;
    ee[knt].dist=x.w;
    ee[knt].next=head[x.u];
    head[x.u]=ee+knt++;
    ee[knt].dest=x.u;
    ee[knt].dist=x.w;
    ee[knt].next=head[x.v];
    head[x.v]=ee+knt++;
}
int pre[maxn][20],deep[maxn],dist[maxn];
void dfs(int u,int f,int w){
    pre[u][0]=f;
    deep[u]=deep[f]+1;
    dist[u]=dist[f]+w;
    for(int i=0;pre[u][i];i++)
        pre[u][i+1]=pre[pre[u][i]][i];
    for(edge*i=head[u];i;i=i->next)
        if(i->dest!=f)
            dfs(i->dest,u,1);
}
int lca(int u,int v){
    if(deep[u]<deep[v])u^=v^=u^=v;
    int delta=deep[u]-deep[v];
    for(int i=0;delta;i++,delta/=2)
        if(delta&1)
            u=pre[u][i];
    if(u==v)
        return u;
    for(int i=19;~i;i--)
        if(pre[u][i]^pre[v][i])
            u=pre[u][i],v=pre[v][i];
    return pre[u][0];
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m)){
        memset(head,knt=cnt=0,sizeof head);
        init();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%s%d",op,&w);
                if(op[0]!='X')
                    addsetedge(nowcoord,downcoord,w);
                scanf("%s%d",op,&w);
                if(op[0]!='X')
                    addsetedge(nowcoord,rightcoord,w);
            }
        }
        std::sort(e,e+cnt,[](const setedge&a,const setedge&b)->bool{
            return a.w>b.w;
        });
        int c=n*m-1;
        for(int i=0;i<cnt&&c;i++)
            if(!same(e[i].u,e[i].v)){
                addedge(e[i]);
                join(e[i].u,e[i].v);
                c--;
            }
        dfs(1,0,0);
        scanf("%d",&q);
        while(q--){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a=a*n+b-n;
            c=c*n+d-n;
            printf("%d\n",dist[a]+dist[c]-2*dist[lca(a,c)]);
        }
    }
    return 0;
}