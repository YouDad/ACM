#include<stdio.h>
#include<string.h>
#include<queue>
const int maxn=235;
struct edge{
    int dest;
    edge*next;
}e[maxn*40],*head[maxn];
std::deque<int>q;
int pre[maxn],nodenum,cnt;
int vis[maxn],nxt[maxn],match[maxn];
char mrk[maxn];
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
int find(int x){return x==pre[x]?x:pre[x]=find(pre[x]);}
void join(int x,int y){x=find(x);y=find(y);if(x!=y)pre[x]=y;}
int root(int u,int v){
    static int cnt=0;cnt++;u^=v^=u^=v;
    while(true){u^=v^=u^=v;
        if(!~u)continue;u=find(u);
        if(vis[u]==cnt)return u;vis[u]=cnt;
        u=~match[u]?nxt[match[u]]:-1;
    }
}
bool aug(int src){
    memset(nxt+1,-1,nodenum*4);
    memset(mrk+1,0,nodenum);
    memset(vis+1,-1,nodenum*4);
    for(int i=0;i<=nodenum;++i)pre[i]=i;
    q.clear();q.push_back(src);mrk[src]=1;
    while(q.size()){
        int u=q.front();q.pop_front();
        for(edge*i=head[u];i;i=i->next){
            int v=i->dest;if(find(u)==find(v))continue;
            if(match[u]==v||mrk[v]==2)continue;
            if(mrk[v]==1){
                int rt=root(u,v);
                if(find(u)!=rt)nxt[u]=v;
                if(find(v)!=rt)nxt[v]=u;
                for(int i=0;i<2;i++)
                for(int a=i?u:v;a!=rt;){
                    int b=match[a],c=nxt[b];
                    if(find(c)!=rt)nxt[c]=b;
                    if(mrk[b]==2)q.push_back(b),mrk[b]=1;
                    if(mrk[c]==2)q.push_back(c),mrk[c]=1;
                    join(a,b);join(b,c);a=c;
                }continue;
            }nxt[v]=u;
            if(~match[v]){
                q.push_back(match[v]);
                mrk[match[v]]=1;mrk[v]=2;
            }else{
                int tmp;
                for(u=v;~u;u=tmp){
                    v=nxt[u];tmp=match[v];
                    match[v]=u;match[u]=v;
                }return true;
            }
        }
    }return false;
}
char map[20][20];int n,m;
inline int abs(int x){return x<0?-x:x;}
void addedges(int x,int y,bool bidir){
    for(int dx=-2;dx<=2;dx++)
    for(int dy=-2;dy<=2;dy++){
        if(abs(dx)==2&&!dy||abs(dy)==2&&!dx||!dx&&!dy)continue;
        int nx=x+dx,ny=y+dy;
        if(nx<0||ny<0||nx>=n||ny>=m)continue;
        if(map[nx][ny]=='.'){
            addedge(x*m+y+1,nx*m+ny+1);
            if(bidir)addedge(nx*m+ny+1,x*m+y+1);
        }
    }
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        printf("Case #%d: daizhenyang ",kase);
        scanf("%d%d",&n,&m);nodenum=n*m;
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        memset(head,cnt=0,sizeof head);
        int kx,ky;
        for(int x=0;x<n;x++)
        for(int y=0;y<m;y++)
        if(map[x][y]=='.')
            addedges(x,y,false);
        else if(map[x][y]=='K')
            kx=x,ky=y;
        memset(match,-1,sizeof match);
        for(int x=0;x<n;x++)
        for(int y=0;y<m;y++)
        if(map[x][y]=='.'&&!~match[x*m+y+1])
            aug(x*m+y+1);
        addedges(kx,ky,true);
        puts(aug(kx*m+ky+1)?"win":"lose");
    }
    return 0;
}