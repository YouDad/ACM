#include<string.h>
#include<stack>
inline int min(int a,int b){return a<b?a:b;}
const int maxn=10005;
struct edge{
    int to;
    struct edge*next;
}e[100005],*head[maxn];
int cnt,id;
int dfsid[maxn],minid[maxn],belong[maxn];
bool ins[maxn];
void addedge(int u,int v){
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
std::stack<int>*s;//别忘了new std::stack<in
void tarjan(int u){
    dfsid[u]=minid[u]=++id;
    s->push(u);ins[u]=true;
    for(edge*i=head[u];i;i=i->next){
        int v=i->to;
        if(dfsid[v]==0)
            tarjan(v),
            minid[u]=min(minid[u],minid[v]);
        else if(ins[v])
            minid[u]=min(minid[u],dfsid[v]);
    }
    if(dfsid[u]==minid[u]){
        for(;s->top()!=u;s->pop()){
            ins[s->top()]=false;
            belong[s->top()]=ans;
        }s->pop();
    }
}