#include<stdio.h>
#include<string.h>
#include<stack>
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2005;
struct edge{
    int dest;
    struct edge*next;
}e[maxn*maxn*2],*head[maxn];
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
    int n,m,a,b,c,d;
    while(~scanf("%d%d",&n,&m)){
        memset(dfsid,bcnt=id=0,sizeof dfsid);
        memset(head,cnt=0,sizeof head);
        while(m--){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a=a*2+c;b=b*2+d;
            addedge(a,b^1);
            addedge(b,a^1);
        }
        for(int i=0;i<n*2;i++)
            if(!dfsid[i])
                tarjan(i);
        for(int i=0;i<n;i++)
            if(belong[i*2]==belong[i*2+1])
                goto NO;
        YES:puts("YES");continue;
        NO:puts("NO");
    }
    return 0;
}