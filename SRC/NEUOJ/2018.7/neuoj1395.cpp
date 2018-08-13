#include<bits/stdc++.h>
#define maxn 105
#define mod 1000000007
#define inf 0x3f3f3f3f3f3f3f3fL
struct qnode
{
    int id;long long dist;
    qnode(int i,long long d){id=i,dist=d;}
    bool operator<(const struct qnode r)const{return dist>r.dist;}
};
long long dist[maxn],map[maxn][maxn],remind[maxn][maxn];
char s[maxn];
bool vis[maxn];
void dijkstra(int src,int n)
{
    memset(vis,false,sizeof vis);
    memset(dist,0x3f,sizeof dist);  ///inf
    std::priority_queue<struct qnode>q;
    dist[src]=0;q.push(qnode(src,0));
    while(q.size()){
        int u=q.top().id;q.pop();vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v])continue;
            long long w=map[u][v];
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push(qnode(v,dist[v]));
            }
        }
    }
}
int main(){
    int n;
    while(~scanf("%d%*c",&n)){
        memset(dist,0x3f,sizeof dist);  ///inf
		memset(remind,0x3f,sizeof remind);
        for(int i=0;i<n;i++){
            gets(s);
            for(int j=0;j<n;j++)
                map[i][j]=s[j]-'0'?s[j]-'0':inf;  //inf
        }
        dijkstra(0,n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i]+map[i][j]==dist[j])
                    remind[i][j]=map[i][j];
        long long ans=1;
        for(int i=1;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++)
                if(remind[j][i]!=inf)
                    cnt++;
            ans=ans*cnt%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}