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
int cnt,pre[maxn],f[maxn],g[maxn];
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
        memset(g,0,sizeof g);
        for(int i=1;i<=n;i++)
            scanf("%d",f+i);
        int u,v;
        while(scanf("%d%d",&u,&v)&&u+v)
            addedge(u,v);
        int rt=bfs();
        while(bfsid->size()){
            u=bfsid->top();bfsid->pop();
            v=f[u]>g[u]?f[u]:g[u];
            f[pre[u]]+=g[u];
            g[pre[u]]+=v;
        }
        printf("%d\n",f[rt]>g[rt]?f[rt]:g[rt]);
    }delete bfsid;
    return 0;
}
//结构体版
#include<stdio.h>
#include<string.h>
struct TreeNode{
    int f;//father
    int b;//brother
    int c;//child
    //special attr:
    int s;//selected dp val
    int u;//unselect dp val
    //special func:
    int max(){return s>u?s:u;}
}node[6005];
void dfs_dp(int rt){
    for(int i=node[rt].c;i;i=node[i].b){
        dfs_dp(i);
        node[rt].s+=node[i].u;
        node[rt].u+=node[i].max();
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(node,0,sizeof node);
        for(int i=1;i<=n;i++)
            scanf("%d",&node[i].s);
        for(int u,v;scanf("%d%d",&u,&v)&&u+v;){
            node[u].f=v;
            node[u].b=node[v].c;
            node[v].c=u;
        }
        int rt=1;//root
        while(node[rt].f)
            rt=node[rt].f;
        dfs_dp(rt);
        printf("%d\n",node[rt].max());
    }
}
//数组版,大概比结构体快,代码量少吧
#include<stdio.h>
#include<string.h>
#define clr(arr) memset(arr,0,sizeof arr)
typedef int array[6005];
array f,b,c,s,u;
int max(int x){return s[x]>u[x]?s[x]:u[x];}
void dfs_dp(int rt){
    for(int i=c[rt];i;i=b[i]){
        dfs_dp(i);
        s[rt]+=u[i];
        u[rt]+=max(i);
    }
}
int main(){
    for(int n;~scanf("%d",&n)){
        clr(f);clr(b);clr(c);clr(u);
        for(int i=1;i<=n;i++)scanf("%d",s+i);
        for(int u,v;scanf("%d%d",&u,&v)&&u+v;)
            b[u]=c[f[u]=v],c[v]=u;
        int rt=1;while(f[rt])rt=f[rt];
        dfs_dp(rt);
        printf("%d\n",max(rt));
    }
}