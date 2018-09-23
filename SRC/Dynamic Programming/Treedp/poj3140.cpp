#include<stdio.h>
#include<string.h>
inline long long abs(long long x){return x<0?-x:x;}
const int maxn=100005;
struct edge{
    int dest;
    struct edge*next;
}e[maxn*2],*head[maxn];
int cnt;
inline void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    e[cnt].dest=u;
    e[cnt].next=head[v];
    head[v]=e+cnt++;
}
long long dp[maxn];
void dfs(int u,int f){
    for(edge*i=head[u];i;i=i->next)
        if(i->dest!=f)
            dfs(i->dest,u),
            dp[u]+=dp[i->dest];
}
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
int ch,res;
int cini(){
    while((ch=nc())<'0'||ch>'9');res=ch-'0';
    while((ch=nc())>='0'&&ch<='9')res=res*10+ch-'0';
    return res;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m,kase=1;
    while(true){
        n=cini();m=cini();
        if(n+m==0)break;
        long long sum=0;
        memset(head,cnt=0,sizeof head);
        for(int i=1;i<=n;i++)
            sum+=dp[i]=cini();
        for(int i=1;i<=m;i++)
            addedge(cini(),cini());
        dfs(1,0);
        long long min=0x3f3f3f3f3f3f3f3fL;
        for(int i=1;i<=n;i++)
            if(min>abs(2*dp[i]-sum))
                min=abs(2*dp[i]-sum);
        printf("Case %d: %lld\n",kase++,min);
    }
    return 0;
}