#include<stdio.h>
#include<string.h>
const int maxn=256*10005;
int next[maxn],q[maxn],ql,qr;
bool vis[maxn];
#define f(i,j) ((i)*256+(j))
#define addedge(u,v) next[u]=v
char op[4];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n,x,y;scanf("%d",&n);
        memset(vis,false,sizeof vis);
        for(int i=0;i<n;i++){
            getchar();op[0]=getchar(),op[1]=getchar();getchar();
            if(op[0]=='a'){
                scanf("%d",&x);
                for(int j=0;j<256;j++)
                    addedge(f(i,j),f(i+1,(j+x)%256));
            }else{
                scanf("%d%d",&x,&y);y--;
                switch(op[1]){
                    case 'e':
                        for(int j=0;j<256;j++)
                            if(j==x)
                                addedge(f(i,j),f(y,j));
                            else
                                addedge(f(i,j),f(i+1,j));
                        break;
                    case 'n':
                        for(int j=0;j<256;j++)
                            if(j!=x)
                                addedge(f(i,j),f(y,j));
                            else
                                addedge(f(i,j),f(i+1,j));
                        break;
                    case 'l':
                        for(int j=0;j<256;j++)
                            if(j<x)
                                addedge(f(i,j),f(y,j));
                            else
                                addedge(f(i,j),f(i+1,j));
                        break;
                    case 'g':
                        for(int j=0;j<256;j++)
                            if(j>x)
                                addedge(f(i,j),f(y,j));
                            else
                                addedge(f(i,j),f(i+1,j));
                        break;
                }
            }
        }
        //bfs start:
        ql=0;qr=1;
        while(qr-ql){
            int v=next[q[ql++]];
            if(v/256==n)
                goto yes;
            else if(!vis[v])
                q[qr++]=v,
                vis[v]=true;
        }
        puts("No");continue;
        yes:puts("Yes");
    }
    return 0;
}