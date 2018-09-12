#include<stdio.h>
#include<string.h>
#include<stack>
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1005;
struct edge{
    int dest;
    struct edge*next;
}e[2005],*head[maxn];
int cnt,id,bcnt;
int dfsid[maxn],minid[maxn],belong[maxn];
bool ins[maxn];
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
std::stack<int>*s;
void tarjan(int u){
    dfsid[u]=minid[u]=++id;
    s->push(u);ins[u]=true;
    for(edge*i=head[u];i;i=i->next){
        int v=i->dest;
        if(dfsid[v]==0)
            tarjan(v),
            minid[u]=min(minid[u],minid[v]);
        else if(ins[v])
            minid[u]=min(minid[u],dfsid[v]);
    }
    if(dfsid[u]==minid[u]){
        for(bcnt++;true;s->pop()){
            ins[s->top()]=false;
            belong[s->top()]=bcnt;
            if(s->top()==u)break;
        }s->pop();
    }
}
int in[maxn],cost[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    s=new std::stack<int>();
    int n,m,u,v;
    while(~scanf("%d%d",&n,&m)){
        memset(dfsid,bcnt=id=0,sizeof dfsid);
        memset(head,cnt=0,sizeof head);
        memset(in,0,sizeof in);
        for(int i=1;i<=n;i++)
            scanf("%d",cost+i);
        while(m--){
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        for(int i=1;i<=n;i++)
            if(!dfsid[i])
                tarjan(i);
        for(int u=1;u<=n;u++)
            for(edge*i=head[u];i;i=i->next)
                if(belong[i->dest]!=belong[u])
                    in[belong[i->dest]]++;
        int ans_people=0,ans_cost=0;
        for(int i=1;i<=bcnt;i++)
            if(!in[i]){
                ans_people++;
                int mincost=0x3f3f3f3f;
                for(int j=1;j<=n;j++)
                    if(belong[j]==i)
                        mincost=min(mincost,cost[j]);
                ans_cost+=mincost;
            }
        printf("%d %d\n",ans_people,ans_cost);
    }
}