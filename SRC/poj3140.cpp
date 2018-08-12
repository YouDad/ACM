#include<stdio.h>
#include<string.h>
inline long long abs(long long x){return x<0?-x:x;}
const int maxn=100005;
struct edge{
    int dest;
    struct edge*next;
}e[maxn<<1],*head[maxn];
int cnt,pre[maxn];
inline void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    e[cnt].dest=u;
    e[cnt].next=head[v];
    head[v]=e+cnt++;
}
long long dp[maxn];
void dfs(int rt){
    for(edge*i=head[rt];i;i=i->next){
        int v=i->dest;
        if(!pre[v]){
            pre[v]=rt;dfs(v);
            dp[rt]+=dp[v];
        }
    }
}
long long cinl()//正数
{
    int ch;
    while((ch=getchar())<'0'||ch>'9');
    long long res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9' )
        res=res*10+ch-'0';
    return res;
}
int main(){
    int n,m;while(scanf("%d%d",&n,&m)&&n+m){
        long long sum=0;static int kase=1;
        memset(head,cnt=0,sizeof head);
        for(int i=1;i<=n;i++)
            sum+=dp[i]=cinl();
        for(int i=1;i<=m;i++)
            addedge(cinl(),cinl());
        memset(pre,0,sizeof pre);pre[1]=1;dfs(1);
        long long min=0x3f3f3f3f3f3f3f3fL;
        for(int i=1;i<=n;i++)
            if(min>abs(2*dp[i]-sum))
                min=abs(2*dp[i]-sum);
        printf("Case %d: %lld\n",kase++,min);
    }
    return 0;
}