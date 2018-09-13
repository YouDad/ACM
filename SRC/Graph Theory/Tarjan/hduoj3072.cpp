#include<stdio.h>
#include<string.h>
#include<stack>
inline int min(int a,int b){return a<b?a:b;}
const int maxn=50005;
struct edge{
    int dest,cost;
    struct edge*next;
}e[100005],*head[maxn];
int cnt,id,bcnt;
int dfsid[maxn],minid[maxn],belong[maxn];
bool ins[maxn];
void addedge(int u,int v,int w){
    e[cnt].dest=v;
    e[cnt].cost=w;
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
int ans[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    s=new std::stack<int>();
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(dfsid,bcnt=id=0,sizeof dfsid);
        memset(head,cnt=0,sizeof head);
        int u,v,w;
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        for(int i=0;i<n;i++)
            if(!dfsid[i])
                tarjan(i);
        memset(ans,0x3f,sizeof ans);
        for(int u=0;u<n;u++)
            for(edge*i=head[u];i;i=i->next){
                int v=i->dest,w=i->cost;
                if(belong[u]!=belong[v]){
                    ans[belong[v]]=min(ans[belong[v]],w);
                }
            }
        int sum=-0x3f3f3f3f;
        for(int i=1;i<=bcnt;i++)
            sum+=ans[i];
        printf("%d\n",sum);
    }
}