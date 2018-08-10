//树形dp f选 g不选 u->v f[u]=w[u]+Σg[v] g[u]=Σmax(f[v],g[v])
#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
const int maxm=6005;
const int maxn=6005;
struct edge{
    int dest;
    struct edge*next;
}e[maxm],*head[maxn];
int cnt,w[maxn],pre[maxn],f[maxn],g[maxn];
void addedge(int u,int v){//v->u
    e[cnt].dest=u;
    e[cnt].next=head[v];
    head[v]=e+cnt++;
    pre[u]=v;
}
std::stack<int>*bfsid;
int bfs(){
    int rt=1;
    while(pre[rt])rt=pre[rt];
    std::queue<int>q;
    q.push(rt);
    while(q.size()){
        int u=q.front();q.pop();bfsid->push(u);
        for(edge*i=head[u];i;i=i->next)
            q.push(i->dest);
    }
    return rt;
}
int main(){
    int n;bfsid=new std::stack<int>();
    while(~scanf("%d",&n)){
        memset(head,cnt=0,sizeof head);
        memset(pre,0,sizeof pre);
        memset(f,0,sizeof f);
        memset(g,0,sizeof g);
        for(int i=1;i<=n;i++)
            scanf("%d",w+i);
        int u,v;
        while(scanf("%d%d",&u,&v)&&u+v)
            addedge(u,v);
        int rt=bfs();
        while(bfsid->size()){
            u=bfsid->top();bfsid->pop();
            f[u]+=w[u];
            v=f[u]>g[u]?f[u]:g[u];
            f[pre[u]]+=g[u];
            g[pre[u]]+=v;
        }
        printf("%d\n",f[rt]>g[rt]?f[rt]:g[rt]);
    }delete bfsid;
    return 0;
}