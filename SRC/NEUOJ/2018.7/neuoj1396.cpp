#include<stdio.h>
#include<string.h>
#include<vector>
const int maxn=1000050;
struct edge{
    int dest;edge*next;
}e[maxn],*head[maxn];
int cnt,pre[maxn],f[maxn],n,father;
int senior[maxn],junior[maxn],res;
long long ans;
void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
void INSERT(int*arr,int x){
    for(;x<maxn;x+=x&-x)arr[x]++;
}
void DELETE(int*arr,int x){
    for(;x<maxn;x+=x&-x)arr[x]--;
}
int query(int*arr,int r){
    for(res=0;r;r-=r&-r)res+=arr[r];return res;
}
void dfs(int u){
    int fathersum=query(junior,f[u]-1);
    INSERT(junior,f[u]);INSERT(senior,f[u]);
    for(edge*i=head[u];i;i=i->next)dfs(i->dest);
    fathersum=query(junior,f[u]-1)-fathersum;
    ans+=(long long)fathersum*query(senior,f[u]-1);
    DELETE(senior,f[u]);
}
/*cini*/int ch,ress;
int cini(){
    while((ch=getchar())<'0'||ch>'9');ress=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')ress=ress*10+ch-'0';
    return ress;
}
int main(){
    while(~scanf("%d",&n)){
        memset(head,ans=cnt=0,sizeof head);
        for(int i=1;i<=n;i++)
            if(pre[i]=father=cini())
                addedge(father,i);
        for(int i=1;i<=n;i++)f[i]=cini();
        memset(senior,0,sizeof senior);
        memset(junior,0,sizeof junior);
        for(int i=1;i<=n;i++)if(!pre[i])dfs(i);
        printf("%lld\n",ans);
    }
    return 0;
}