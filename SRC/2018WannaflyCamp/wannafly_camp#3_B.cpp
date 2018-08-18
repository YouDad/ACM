#include<stdio.h>
#include<string.h>
const int maxn=1e6+5;
const int mod=1e9+7;
struct edge{
    int dest;
    struct edge*next;
}e[maxn<<1],*head[maxn];int cnt;
inline void addedge(int u,int v){
    e[cnt].dest=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    e[cnt].dest=u;
    e[cnt].next=head[v];
    head[v]=e+cnt++;
}
int pre[maxn];
long long children[maxn];
void childdfs(int rt){
    children[rt]=1;
    for(edge*i=head[rt];i;i=i->next){
        int v=i->dest;
        if(pre[v]==0){
            pre[v]=rt;
            childdfs(v);
            children[rt]=children[rt]*(children[v]+1)%mod;
        }
    }
}
long long father[maxn];
long long pp[maxn];//prefixproduct
long long sp[maxn];//suffixproduct
int child[maxn];
void fatherdfs(int rt){
    int size=0;
    for(edge*i=head[rt];i;i=i->next)
		if(pre[rt]!=i->dest){
			child[size++]=i->dest;
			sp[size]=pp[size]=children[i->dest]+1;
		}
    for(int i=2;i<=size;i++)
        pp[i]=pp[i]*pp[i-1]%mod;
    for(int i=size-1;i>=1;i--)
        sp[i]=sp[i]*sp[i+1]%mod;
    pp[0]=sp[size+1]=1;
    for(int j=0;j<size;j++)
        father[child[j]]=1+pp[j]*sp[j+2]%mod*father[rt]%mod;
    for(edge*i=head[rt];i;i=i->next)
		if(pre[rt]!=i->dest)
			fatherdfs(i->dest);
}
int main(){
    for(int n;~scanf("%d",&n);){
        memset(head,cnt=0,sizeof head);
        for(int i=0,u,v;i<n-1;i++)
            scanf("%d%d",&u,&v),
            addedge(u,v);
        memset(pre,0,sizeof pre);
        pre[1]=1;childdfs(1);
        father[1]=1;fatherdfs(1);
        for(int i=1;i<=n;i++)
            printf("%lld\n",children[i]*father[i]%mod);
    }
    return 0;
}