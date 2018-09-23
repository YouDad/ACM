#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=105;
char map[maxn][maxn];
bool vis[maxn][maxn][6];
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
struct qnode{
    int x,y,t,o;
    qnode(int x,int y,int t,int o):x(x),y(y),t(t),o(o){}
    bool operator<(const qnode&other)const{
        return t>other.t;
    }
};
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m;
    while(scanf("%d%d%*c",&n,&m)&&n+m){
        memset(vis,false,sizeof vis);
        for(int i=0;i<n;i++)gets(map[i]);
        std::priority_queue<qnode>pq;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map[i][j]=='S')
                    map[i][j]='.',
                    vis[i][j][0]=true,
                    pq.push(qnode(i,j,0,0));
        int ans=-1;
        while(pq.size()){
            qnode u=pq.top();pq.pop();
            for(int i=0;i<4;i++){
                int x=u.x+dx[i],y=u.y+dy[i],t=u.t,o=u.o;
                if(x<0||y<0||x>=n||y>=m)continue;
                switch(map[x][y]){
                    case '.':t++;break;
                    case '#':o--,t+=2;break;
                    case 'B':o+=o<5;t++;break;
                    case 'P':break;
                    case 'T':ans=++t;goto output;
                }
                if(o<0)continue;if(vis[x][y][o])continue;
                pq.push(qnode(x,y,t,o));vis[x][y][o]=true;
            }
        }output:printf("%d\n",ans);
    }
    return 0;
}