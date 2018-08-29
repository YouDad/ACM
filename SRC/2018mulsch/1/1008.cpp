#include<stdio.h>
#include<string.h>
#include<stack>
const int maxn=1000005;
const long long mod=1e9+7;
struct Node{int v,l,r;}node[maxn];
int dp[maxn];
long long inv[maxn]={0,1};
int build(int n){
    int rt=0;std::stack<int>s;
    for(int i=1,pre=0;i<=n;i++,pre=0){
        while(s.size()&&node[s.top()].v<node[i].v)
            pre=s.top(),s.pop();
        if(s.size())node[s.top()].r=i;else rt=i;
        node[i].l=pre;s.push(i);
    }return rt;
}
void dfs(int u){
    if(!u)return;
    Node&n=node[u];
    dfs(n.l);dfs(n.r);
    dp[u]=dp[n.l]+dp[n.r]+1;
}
/*nc*/inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
/*cini*/int ch,res;
int cini(){
    while((ch=nc())<'0'||ch>'9');res=ch-'0';
    while((ch=nc())>='0'&&ch<='9')res=res*10+ch-'0';
    return res;
}
int main(){
    for(int i=2;i<maxn;i++)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    int t=cini();
    while(t--){
        int n=cini();
        memset(node,0,(n+1)*12);
        memset(dp,0,n+1<<2);
        for(int i=1;i<=n;i++)
            node[i].v=cini();
        dfs(build(n));
        long long ans=inv[2]*n%mod;
        for(int i=1;i<=n;i++)
            ans=ans*inv[dp[i]]%mod;
        printf("%lld\n",ans);
    }
    return 0;
}