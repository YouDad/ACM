#include<queue>
#include<memory.h>
#include<stdio.h>
#include<stdlib.h>
#define maxn 1005
#define maxm 1000005
struct edge
{
    int dest;
    double dist;
    struct edge*next;
}e[maxm],*head[maxn];
int cnt;
inline void addedge(int u,int v,double w){
    e[cnt].next=head[u];
    e[cnt].dist=w;
    e[cnt].dest=v;
    head[u]=e+cnt++;
	
    e[cnt].next=head[v];
    e[cnt].dist=w;
    e[cnt].dest=u;
    head[v]=e+cnt++;
}
struct qnode
{
    int id;double dist;
    qnode(int i,double d){id=i,dist=d;}
    bool operator<(const struct qnode r)const{return dist>r.dist;}
};
bool vis[maxn];
double dist[maxn];
void dijkstra(int src,int n)
{
    memset(vis,false,sizeof vis);
	for(int i=0;i<=n;i++)
		dist[i]=1e20;
    std::priority_queue<struct qnode>q;
    dist[src]=0;q.push(qnode(src,0));
    while(q.size()){
        int u=q.top().id;
        double d=q.top().dist;q.pop();
        if(dist[u]!=d)continue;
        vis[u]=true;
        for(struct edge*ptr=head[u];ptr;ptr=ptr->next){
            int v=ptr->dest;
            if(vis[v])continue;
            double w=ptr->dist;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push(qnode(v,dist[v]));
            }
        }
    }
}
#include<vector>
#include<math.h>
int a,b;
double sqrtab;
double distance(int c,int x,int y){
	return fabs(a*x+b*y+c+0.0)/sqrtab;
}
struct circle{
	int x,y,r,i;
	circle(int xx,int yy,int rr,int ii){x=xx;y=yy;r=rr;i=ii;}
};
double p2p(circle p1,circle p2){
	return sqrt(0.0+(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main(){
	//freopen("1.txt","r",stdin);
	int n,c1,c2,x,y,r;
	while(~scanf("%d%d%d%d%d",&n,&a,&b,&c1,&c2)){
		memset(head,0,sizeof head);cnt=0;
		sqrtab=sqrt(0.0+a*a+b*b);
		double linedist=abs(c1-c2)/sqrtab;
		addedge(1000,1001,linedist);
		std::vector<circle>v;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&r);
			double d1=distance(c1,x,y)-r,d2=distance(c2,x,y)-r;
			if(d1<linedist&&d2<linedist){
				v.push_back(circle(x,y,r,i));
				addedge(1000,i,d1<0?0:d1);
				addedge(1001,i,d2<0?0:d2);
			}
		}
		for(int i=0;i<v.size();i++)
			for(int j=i+1;j<v.size();j++){
				double d=p2p(v[i],v[j])-v[i].r-v[j].r;
				if(d<linedist)
					addedge(v[i].i,v[j].i,d<0?0:d);
			}
		dijkstra(1000,1001);
		printf("%lf\n",dist[1001]);
	}
    return 0;
}