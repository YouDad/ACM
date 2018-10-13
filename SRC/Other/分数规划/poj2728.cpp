#include<stdio.h>
#include<string.h>
#include<math.h>
struct Node{
    int x,y,z;
}node[1005];
double dist[1005][1005];
double cost[1005][1005];
double dis[1005];
bool vis[1005];
int n;
bool check(double mid){
    memset(vis,false,sizeof vis);
    memset(dis,0x7f,sizeof dis);
    dis[0]=0;int cnt=0;
    while(cnt<n){
        double mindist=1e99;int u;
        for(int i=0;i<n;i++)
            if(!vis[i]&&mindist>dis[i])
                mindist=dis[u=i];
        vis[u]=true;cnt++;
        for(int v=0;v<n;v++)
            if(!vis[v]&&dis[v]>cost[u][v]-mid*dist[u][v])
                dis[v]=cost[u][v]-mid*dist[u][v];
    }double sum=0;
    for(int i=0;i<n;i++)sum+=dis[i];
    return sum>=0;
}
#define dis(i,j) sqrt(0.0+(node[i].x-node[j].x)*(node[i].x-node[j].x)+\
                          (node[i].y-node[j].y)*(node[i].y-node[j].y))
#define cst(i,j) (node[i].z>node[j].z?node[i].z-node[j].z:node[j].z-node[i].z)
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%d",&n)&&n){
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].z);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j]=dis(i,j),
            cost[i][j]=cst(i,j);
        double L=0,R=10000000,ans=0;
        while(R-L>=1e-4){
            double mid=(L+R)/2;
            if(check(mid))
                L=ans=mid;
            else R=mid;
        }printf("%.3lf\n",ans);
    }
    return 0;
}