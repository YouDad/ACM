#include<stdio.h>
#include<string.h>
#include<queue>
char map[505][505];
int flag1[505][505],n,m,flag2[505][505];
const int S=1,R=2,D=3,INF=0x3f3f3f3f;//status:standing r:right d:down
const int LEFT=1,RIGHT=2,BACK=3,FRONT=4;
#define retpose(x,y,status) return pose(x,y,i+1,status)
int min(int a,int b){return a<b?a:b;}
struct pose{
    int x,y,status,i;
    pose(int a,int b,int c,int d){
        x=a;y=b;i=c;status=d;
    }
    pose vary(int mode){
        switch(status){
            case S:switch(mode){
                case LEFT:retpose(x,y-2,R);
                case RIGHT:retpose(x,y+1,R);
                case BACK:retpose(x-2,y,D);
                case FRONT:retpose(x+1,y,D);
            }
            case R:switch(mode){
                case LEFT:retpose(x,y-1,S);
                case RIGHT:retpose(x,y+2,S);
                case BACK:retpose(x-1,y,R);
                case FRONT:retpose(x+1,y,R);
            }
            case D:switch(mode){
                case LEFT:retpose(x,y-1,D);
                case RIGHT:retpose(x,y+1,D);
                case BACK:retpose(x-1,y,S);
                case FRONT:retpose(x+2,y,S);
            }
        }
    }
    bool check(){
        if(x<0||y<0)return false;
        if(status==R)if(x>=n-1)return false;
        if(status==D)if(y>=m-1)return false;
        switch(status){
            case S:return flag1[x][y]==INF&&map[x][y]!='#'&&map[x][ y ]!='E';
            case R:return flag2[x][y]%D==0&&map[x][y]!='#'&&map[x][y+1]!='#';
            case D:return flag2[x][y]%R==0&&map[x][y]!='#'&&map[x+1][y]!='#';
        }
    }
    pose&flag(){
        switch(status){
            case S:flag1[x][y]=min(flag1[x][y],i);return *this;
            default:flag2[x][y]+=status;return *this;
        }
    }
};
int main(){
    while(scanf("%d%d%*c",&n,&m)&&n+m){
        int sx=0,sy=0,tx,ty,status=S;
        memset(flag1,INF,sizeof flag1);
        memset(flag2,0,sizeof flag2);
        for(int i=0;i<n;i++)gets(map[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map[i][j]=='O')
                    tx=i,ty=j;
                else if(map[i][j]=='X'&&sx)
                    status=i==sx?R:D;
                else if(map[i][j]=='X')
                    sx=i,sy=j;
        std::queue<pose>q;
        q.push(pose(sx,sy,1,status));
        flag1[sx][sy]=1;
        while(q.size()){
            pose u=q.front();q.pop();
            for(int i=1;i<=4;i++)
                if(u.vary(i).check())
                    q.push(u.vary(i).flag());
        }
        if(flag1[tx][ty]!=INF)printf("%d\n",flag1[tx][ty]-1);
        else puts("Impossible");
    }
    return 0;
}