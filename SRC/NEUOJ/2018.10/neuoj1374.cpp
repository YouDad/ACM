#include<stdio.h>
#include<string.h>
#include<queue>
struct node{int x,y,dir;
    node(int a=0,int b=0,int c=0){
        x=a;y=b;dir=c;}};
bool vis[10][10005];int hor[10][10005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        memset(hor,-1,sizeof hor);memset(vis,false,sizeof vis);
        for(int i=0,a,b,c,d;i<k;i++)
            scanf("%d%d%d%d",&a,&b,&c,&d),hor[a][b]=hor[c][d]=a==c;
        std::queue<node>q;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(hor[i][j]==-1){
            q.push(node(i,j,-1));goto out;
        }out:;int ans=-1;
        while(q.size()){
            int x=q.front().x,y=q.front().y,dir=q.front().dir;q.pop();ans++;vis[x][y]=true;
            if(x>2   &&dir!=2&&hor[x-1][y]==0&&!vis[x-2][y])q.push(node(x-2,y,0));
            if(y>2   &&dir!=3&&hor[x][y-1]==1&&!vis[x][y-2])q.push(node(x,y-2,1));
            if(x<=n-2&&dir!=0&&hor[x+1][y]==0&&!vis[x+2][y])q.push(node(x+2,y,2));
            if(y<=m-2&&dir!=1&&hor[x][y+1]==1&&!vis[x][y+2])q.push(node(x,y+2,3));
        }printf("%d\n",ans);
    }
    return 0;
}