#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=505;
struct edge{
    int dest;
    struct edge*next;
}e[maxn*3],*head[maxn];
int cnt,ideg[maxn],ans[maxn];
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    ideg[v]++;
}
void toposort(int n){
    cnt=0;
    std::priority_queue<int>pq;
    for(int i=1;i<=n;i++)
        if(ideg[i]==0)
            pq.push(-i);
    while(!pq.empty()){
        int u=-pq.top(),v;
        pq.pop();
        ans[cnt++]=u;
        for(edge*i=head[u];i;i=i->next){
            v=i->dest;
            if(--ideg[v]==0)
                pq.push(-v);
        }
    }
}
int main(){
    for(int n,m;~scanf("%d%d",&n,&m);){
        memset(head,cnt=0,sizeof head);
        memset(ideg,0,sizeof ideg);
        for(int u,v;m--;){
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        toposort(n);
        for(int i=0;i<n;i++)
            printf("%d%c",ans[i]," \n"[i==n-1]);
    }
    return 0;
}