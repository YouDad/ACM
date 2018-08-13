#include<stdio.h>
#include<string.h>
#include<algorithm>
#define clr(arr) memset(arr,0,sizeof arr)
typedef int array[10005];
struct edge{
    int dest,dist;
    struct edge*next;
}e[10005],*head[10005];
array pre,dpf,dp1,dp2,pass;
//pre:父节点 dp1:走子节点最远距离 dp2:不经过dp1的最远距离
//pass:最远距离经过的第一个点 dpf:走祖节点的最远距离
int cnt=0;
void addedge(int u,int v,int w){//u is father of v
    e[cnt].dist=w;
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    pre[v]=u;
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
void ansdfs(int u){
    int v,w;
    for(edge*i=head[u];i;i=i->next){
        v=i->dest;w=i->dist;
        if(pass[u]==v)
            dpf[v]=w+std::max(dp2[u],dpf[u]);
        else
            dpf[v]=w+std::max(dp1[u],dpf[u]);
        ansdfs(v);
    }
}
int main(){
    for(int n;~scanf("%d",&n);cnt=0){
        clr(pre);clr(dpf);clr(head);
        for(int u,v=2,w;v<=n&&scanf("%d%d",&u,&w);v++)
            addedge(u,v,w);
        predfs(1);
		ansdfs(1);
        for(int i=1;i<=n;i++)
            printf("%d\n",std::max(dpf[i],dp1[i]));
    }
    return 0;
}