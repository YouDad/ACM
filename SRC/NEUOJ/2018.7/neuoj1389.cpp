/*
    思路:简单bfs
    n2复杂度 maxn~2000
*/
#include<stdio.h>
#include<queue>
#include<utility>
#include<memory.h>
struct WeightPoint{
    int x,y,w;
    WeightPoint(int xx,int yy,int ww){x=xx;y=yy;w=ww;}
};
bool vis[2002*2002];
int main(){
    int n,m,k,x,y;
    while(~scanf("%d%d%d",&n,&m,&k)){
        memset(vis,false,sizeof vis);
        for(int i=0;i<2002;i++)
            vis[i]=vis[i+m*2002+2002]=vis[2002*i]=vis[2002*i+n+1]=true;
        std::queue<WeightPoint>q;
        while(k--)
            scanf("%d%d",&x,&y),vis[x*2002+y]=true,
            q.push(WeightPoint(x,y,0));
        int ansx=2002,ansy=2002,answ=-1;
        while(q.size()){
            WeightPoint p=q.front();q.pop();
            if(p.w>answ)answ=p.w,ansx=p.x,ansy=p.y;
            if(p.w==answ)
                if(p.x<ansx)
                    ansx=p.x,ansy=p.y;
                else if(p.x==ansx&&p.y<ansy)
                    ansy=p.y;
            if(vis[p.x*2002+p.y+1]==false)
                vis[p.x*2002+p.y+1]=true,
                q.push(WeightPoint(p.x,p.y+1,p.w+1));
            if(vis[p.x*2002+p.y-1]==false)
                vis[p.x*2002+p.y-1]=true,
                q.push(WeightPoint(p.x,p.y-1,p.w+1));
            if(vis[p.x*2002+p.y+2002]==false)
                vis[p.x*2002+p.y+2002]=true,
                q.push(WeightPoint(p.x+1,p.y,p.w+1));
            if(vis[p.x*2002+p.y-2002]==false)
                vis[p.x*2002+p.y-2002]=true,
                q.push(WeightPoint(p.x-1,p.y,p.w+1));
        }
        printf("%d %d\n",ansx,ansy);
    }
    return 0;
}