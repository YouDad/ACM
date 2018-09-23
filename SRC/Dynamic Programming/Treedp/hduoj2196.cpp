#include<stdio.h>
#include<string.h>
#define clr(arr) memset(arr,0,sizeof arr)
typedef int array[10005];
struct edge{
    int dest,dist;
    struct edge*next;
}e[10005],*head[10005];
array dpf,dp1,dp2,pass;
//dp1:走子节点最远距离 dp2:不经过dp1的最远距离
//pass:最远距离经过的第一个点 dpf:走祖节点的最远距离
int cnt=0;
void addedge(int u,int v,int w){//u is father of v
    e[cnt].dist=w;
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
}
void predfs(int u){
    int max=0,maxi=0,secmax=0,v,w;
    for(edge*i=head[u];i;i=i->next){
        v=i->dest;w=i->dist;
        predfs(v);
        if(max<dp1[v]+w){
            secmax=max;
            max=dp1[v]+w;
            maxi=v;
        }else if(secmax<dp1[v]+w){
            secmax=dp1[v]+w;
        }
    }
    dp1[u]=max;
    dp2[u]=secmax;
    pass[u]=maxi;
}
int max(int a,int b){return a>b?a:b;}
void ansdfs(int u){
    int v,w;
    for(edge*i=head[u];i;i=i->next){
        v=i->dest;w=i->dist;
        dpf[v]=w+max(pass[u]==v?dp2[u]:dp1[u],dpf[u]);
        ansdfs(v);
    }
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    for(int n;~scanf("%d",&n);cnt=0){
        memset(head,0,sizeof head);
        for(int u,v=2,w;v<=n;v++)
            scanf("%d%d",&u,&w),
            addedge(u,v,w);
        predfs(1);dpf[1]=0;ansdfs(1);
        for(int i=1;i<=n;i++)
            printf("%d\n",max(dpf[i],dp1[i]));
    }
    return 0;
}