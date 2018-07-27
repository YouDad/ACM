#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 105
struct edge{int to,next,w;};
edge e[maxn];
int head[maxn];
void addedge(int x,int y,int w)
{
    static int cnt=0;
    e[cnt].to=y;
    e[cnt].next=head[x];
    e[cnt].w=w;
    head[x]=cnt++;
}
int dis[maxn];
int ring[maxn];
bool vis[maxn];
void Spfa(int u,int n)
{
    int i,src,dest;
    queue<int> q;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(ring,0,sizeof(ring));
    q.push(u);
    vis[u]=true;
    dis[u]=0;
    while(!q.empty())
    {
        src=q.front();q.pop();
        vis[src]=false;
        for(i=head[src];i!=-1;i=e[i].next)
        {
            dest=e[i].to;
            if(dis[dest]>dis[src]+e[i].w)
            {
                dis[dest]=dis[src]+e[i].w;
                if(!vis[dest])
                {
                    q.push(dest);
                    vis[dest]=true;
                    if(++ring[dest]>n)
                        return ;
                }
            }
        }
    }
    return ;
}
int test()
{
    int n,m;
    int begin,end;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;++i)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
    }
    scanf("%d%d",&begin,&end);
    Spfa(begin,n);
    printf("%d\n",dis[end]) ;
    return 0;
}