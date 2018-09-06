#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
char map[25][25];
int flag[25][25],dist[11][11],n,m;
const int L=1,R=2,U=3,D=4;
struct point{
    int x,y,i;
    point(int a=0,int b=0,int c=0){
        x=a;y=b;i=c;
    }
    point move(int direction){
        switch(direction){
            case L:return point(x,y-1,i+1);
            case R:return point(x,y+1,i+1);
            case U:return point(x-1,y,i+1);
            case D:return point(x+1,y,i+1);
        }
    }
    bool check(){
        if(x<0||y<0||x>=n||y>=m)return false;
        return map[x][y]!='x'&&flag[x][y]==0;
    }
    point&mark(){
        flag[x][y]=i;
        return*this;
    }
}p;
int best,vsize;
void dfs(int s,int u,int sum){
    if(s+1==1<<vsize&&best>sum)best=sum;
    if(sum>best||s+1==2<<vsize)return;
    for(int i=0;i<vsize;i++)
        if(!(s&1<<i))
            dfs(s|1<<i,i,sum+dist[u][i]);
}
int main(){
    while(scanf("%d%d%*c",&m,&n)&&n+m){
        for(int i=0;i<n;i++)gets(map[i]);
        std::vector<point>v(1);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map[i][j]=='o')
                    v[0]=point(i,j,1);
                else if(map[i][j]=='*')
                    v.push_back(point(i,j,1));
        std::queue<point>q;vsize=v.size();
        memset(dist,0,sizeof dist);
        for(int i=0;i<vsize;i++){
            memset(flag,0,sizeof flag);
            q.push(v[i].mark());
            while(q.size()){
                p=q.front();q.pop();
                for(int i=1;i<=4;i++)
                    if(p.move(i).check())
                        q.push(p.move(i).mark());
            }
            for(int j=0;j<vsize;j++)
                dist[i][j]=flag[v[j].x][v[j].y]-1;
        }
        for(int i=1;i<vsize;i++)
            if(dist[0][i]==-1){
                best=-1;goto end;
            }
        best=0x3f3f3f3f;
        dfs(1,0,0);
        end:printf("%d\n",best);
    }
    return 0;
}