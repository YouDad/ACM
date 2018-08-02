const int maxn=200+5;
const int maxm=200+5;
const int inf=0x3f3f3f3f;
struct edge{
    int dest,cap;
    struct edge*next;
}e[maxm],*head[maxn];
int cnt,dist[maxn],gap[maxn];
inline void addedge(int u, int v, int w){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    e[cnt].cap=w;
    head[u]=e+cnt++;
}
int sap(int src,int dest,int n)
{
    int flow=0,top=0,u=src;
    edge*cur[maxn];
    std::vector<int>vsrc(maxn,0);
    std::vector<edge*>path(maxn,0);
    memset(dist,0,sizeof dist);
    memset(gap,0,sizeof gap);gap[0]=1;
    std::queue<int>q;q.push(dest);
    while(q.size()){    //一个bfs创建层次图和gap
        int u=q.front();q.pop();
        for(edge*i=head[u];i;i=i->next){
            int v=i->dest;
            if(dist[v]||v==dest)continue;
            q.push(v);
            dist[v]=dist[u]+1;
            ++gap[dist[v]];
        }
    }
    memcpy(cur,head,sizeof head);
    while(dist[src]<n){
        if(u==dest){    //把增广路径上的最大流选出来,加到总流里
            int minflow=inf,minsub;
            for(int i=0;i<top;i++)  //选出来
                if(minflow>path[i]->cap)
                    minflow=path[i]->cap,minsub=i;
            for(int i=0;i<top;i++)  //更新图
                path[i]->cap-=minflow,
                e[path[i]-e^1].cap+=minflow;
            flow+=minflow;          //答案加上
            top=minsub;
            u=vsrc[minsub];
        }
        if(u!=dest&&gap[dist[u]-1]==0)break;
        for(edge*i=cur[u];i;i=i->next)  //从cur[u]继续找可增广路径
            if(i->cap&&dist[u]==dist[i->dest]+1)
                if(i){              //找到了
                    cur[u]=i;       //下次从i开始找
                    path[top]=i;    //把路径记录
                    vsrc[top++]=u;  //把起点记录
                    u=i->dest;      //点变成这条边的下一个点
                }
                else{               //没找到
                    int min=n;
                    for(i=head[u];i;i=i->next)  //从头找可增广路径
                        if(i->cap&&min>dist[i->dest])
                            min=dist[i->dest],
                            cur[u]=i;
                    gap[dist[u]]--;     //更新gap
                    dist[u]=min+1;      //更新层次图
                    gap[dist[u]]++;     //更新gap
                    if(u!=src)
                        u=vsrc[--top];
                }
    }
    return flow;
}