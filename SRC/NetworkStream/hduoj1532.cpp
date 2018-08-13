#include<bits/stdc++.h>
const int maxn=200+5;
const int maxm=200+5;
const int inf=0x3f3f3f3f;
struct edge{
    int src,dest,cap;
    struct edge*next;
}e[maxm],*head[maxn];
int cnt,dep[maxn],gap[maxn];
inline void addedge(int u, int v, int w){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    e[cnt].cap=w;
    e[cnt].src=u;
    head[u]=e+cnt++;
}
int sap(int src,int dest,int n)
{
    int ret=0,S[maxn],top=0,u=src;
    edge*cur[maxn];
    std::queue<int>q;
    memset(dep,-1,sizeof dep);
    memset(gap,0,sizeof gap);
    q.push(dest);
    gap[0]=1;
    dep[dest]=0;
    while(q.size()){
        int u=q.front();q.pop();
        for(edge*i=head[u];i;i=i->next){
            int v=i->dest;
            if(dep[v]+1)continue;
            q.push(v);
            dep[v]=dep[u]+1;
            ++gap[dep[v]];
        }
    }
    memcpy(cur,head,sizeof head);
    while(dep[src]<n){
        if(u==dest){
            int temp=inf,inser;
            for(int i=0;i<top;i++)      //find a minimum capacity,id=inser
                if(temp>e[S[i]].cap)
                    temp=e[S[i]].cap,inser=i;
            for(int i=0;i<top;i++)      //every odd edge capacity minus minimum capacity,even edge capacity add minimum capacity
                e[S[i]].cap-=temp,
                e[S[i]^1].cap+=temp;
            ret+=temp;
            top=inser;
            u=e[S[inser]].src;
        }
        if(u!=dest&&gap[dep[u]-1]==0)break;          //出现断层，无增广路
        edge*i;
        for(i=cur[u];i;i=i->next)
            if(i->cap&&dep[u]==dep[i->dest]+1)
                break;
        if(i){
            cur[u]=i;
            S[top++]=i-e;
            u=i->dest;
        }
        else{
            int min=n;
            for(i=head[u];i;i=i->next)
                if(i->cap&&min>dep[i->dest])
                    min=dep[i->dest],
                    cur[u]=i;
            gap[dep[u]]--;
            dep[u]=min+1;
            gap[dep[u]]++;
            if(u!=src)
                u=e[S[--top]].src;
        }
    }
    return ret;
}
int main()
{
    int u,v,w,m,n;
    while(~scanf("%d%d",&m,&n)){
        cnt=0;memset(head,0,sizeof head);
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,0);
        }
        printf("%d\n",sap(1,n,n));
    }
    return 0;
}