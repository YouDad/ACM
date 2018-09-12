#include<stdio.h>
#include<string.h>
#include<stack>
inline int min(int a,int b){return a<b?a:b;}
const int maxn=20005;
struct edge{
    int dest;
    struct edge*next;
}e[50005],*head[maxn];
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
int in[maxn],out[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    s=new std::stack<int>();
    int t;scanf("%d",&t);
    while(t--){
        int n,m,u,v;scanf("%d%d",&n,&m);
        memset(head,cnt=0,sizeof head);
        memset(dfsid,bcnt=id=0,sizeof dfsid);
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        while(m--){
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        for(int i=1;i<=n;i++)
            if(!dfsid[i])
                tarjan(i);
        if(bcnt==1){
            puts("0");
            continue;
        }
        for(int u=1;u<=n;u++)
            for(edge*i=head[u];i;i=i->next)
                if(belong[u]!=belong[i->dest])
                    in[belong[i->dest]]=1,out[belong[u]]=1;
        int icnt=bcnt,ocnt=bcnt;
        for(int i=1;i<=bcnt;i++){
            icnt-=in[i];
            ocnt-=out[i];
        }
        printf("%d\n",icnt>ocnt?icnt:ocnt);
    }
    return 0;
}