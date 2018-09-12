#include<string.h>
#include<stack>
inline int min(int a,int b){return a<b?a:b;}
const int maxn=10005;
struct edge{
    int dest;
    struct edge*next;
}e[100005],*head[maxn];
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
//s=new std::stack<int>();
//memset(dfsid,bcnt=id=0,sizeof dfsid);
//memset(head,cnt=0,sizeof head);
//if dfsid == 0 meaning this isn't be visited