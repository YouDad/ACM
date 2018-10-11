#include<stdio.h>
int A[10][10],dx[105],dy[105];
int kmap[10][10];
const int knight=0,bishop=1,rock=2;
int abs(int x){return x<0?-x:x;}
struct node{int x,y;
    node xx(int i){
        node z=*this;
        z.y+=i;return z;
    }
    node yy(int i){
        node z=*this;
        z.x+=i;return z;
    }
}dp[2][3];
node min(node a,node b){
    if(a.x==b.x)
        if(a.y<b.y)
            return a;
        else return b;
    else if(a.x<b.x)
        return a;
    return b;
}
int func(int x,int person){
    switch(person){
        case knight:return kmap[dx[x]][dy[x]];
        case bishop:
        if((dx[x]+dy[x])%2)return 0x3f3f3f3f;
        return 1+(dx[x]!=dy[x]);
        case rock:return (dx[x]!=0)+(dy[x]!=0);
    }
}
const int kdx[]={-2,-2,-1,-1,1,1,2,2};
const int kdy[]={-1,1,-2,2,2,-2,1,-1};
#include<queue>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    std::queue<int>q;q.push(0);kmap[0][0]=-1;
    while(q.size()){
        int u=q.front(),x=u%10,y=u/10%10,z=u/100;q.pop();
        for(int i=0;i<8;i++){
            int nx=x+kdx[i],ny=y+kdy[i];
            if(nx>=0&&nx<10)if(ny>=0&&ny<10)
            if(kmap[nx][ny]==0)kmap[nx][ny]=z+1,
            q.push(nx+(ny)*10+z*100+100);
        }
    }
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);
    int nowx,nowy;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(A[i][j]==1){
        nowx=i,nowy=j;
        goto ok;
    }ok:;
    for(int k=1;k<=n*n;k++){
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(A[i][j]==k+1){
            dx[k]=abs(i-nowx);
            dy[k]=abs(j-nowy);
            nowx=i;nowy=j;
            goto ok2;
        }ok2:;
    }
    for(int i=1;i<n*n;i++){
        for(int j=0;j<3;j++){
            node ans;ans.x=0x3f3f3f3f;
            for(int k=0;k<3;k++){
                ans=min(ans,dp[1-i%2][k].xx(j!=k).yy(func(i,k)+(j!=k)));
            }dp[i%2][j]=ans;
        }
    }
    node ans;ans.x=0x3f3f3f3f;
    for(int i=0;i<3;i++)
        ans=min(ans,dp[1-n*n%2][i]);
    printf("%d %d\n",ans.x,ans.y);
    return 0;
}