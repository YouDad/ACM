#include<stdio.h>
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
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    s=new std::stack<int>();
    int n,m,u,v;
    while(~scanf("%d%d",&n,&m)){
        memset(head,cnt=0,sizeof head);
        memset(dfsid,id=bcnt=0,sizeof dfsid);
        for(int i=0;i<n;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(a+3*n,b);
            addedge(a+3*n,c);
            addedge(b+3*n,a);
            addedge(c+3*n,a);
        }
        while(m--){
            scanf("%d%d",&u,&v);
            addedge(u,v+3*n);
            addedge(v,u+3*n);
        }
        for(int i=1;i<=6*n;i++)
            if(!dfsid[i])
                tarjan(i);
        for(int i=1;i<=3*n;i++)
            if(belong[i]==belong[i+3*n])
                goto no;
        yes:puts("yes");continue;
        no:puts("no");
    }
    return 0;
}