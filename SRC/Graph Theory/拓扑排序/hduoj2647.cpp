#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=10005;
struct edge{
    int dest;
    struct edge*next;
}e[maxn*2],*head[maxn];
int ideg[maxn],cnt;
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    ideg[v]++;
}
int toposort(int n){
    int ans=0,$=888,k=0,remaind=n;
    std::queue<int>q;
    while(remaind){
        for(int i=1;i<=n;i++)
            if(ideg[i]==0)
                q.push(i),ideg[i]--;
        if(q.size()==0&&remaind)
            return -1;
        ans+=$++*q.size();
        remaind-=q.size();
        while(!q.empty()){
            int u=q.front();q.pop();
            for(edge*i=head[u];i;i=i->next)
                ideg[i->dest]--;
        }
    }
    return ans;
}
int main(){
    for(int n,m;~scanf("%d%d",&n,&m);){
        memset(head,cnt=0,sizeof head);
        memset(ideg,0,sizeof ideg);
        for(int u,v;m--;){
            scanf("%d%d",&u,&v);
            addedge(v,u);
        }
        printf("%d\n",toposort(n));
    }
    return 0;
}