#include<stdio.h>
#include<string.h>
const int maxn=10005;
struct edge{
	int dest;
	struct edge*next;
}e[maxn<<1],*head[maxn];
int cnt=0,pre[maxn];
void addedge(int u,int v){
	e[cnt].dest=v;
	e[cnt].next=head[u];
	head[u]=e+cnt++;
	e[cnt].dest=u;
	e[cnt].next=head[v];
	head[v]=e+cnt++;
}
int nodenum[maxn];
void dfs(int rt){
	for(edge*i=head[rt];i;i=i->next){
		int v=i->dest;
		if(!pre[v]){
			pre[v]=rt;dfs(v);
			nodenum[rt]+=nodenum[v];
		}
	}
	nodenum[rt]++;
}
int main(){
	int n;while(~scanf("%d",&n)){
		memset(head,cnt=0,sizeof head);
		for(int i=0,u,v;i<n-1;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		memset(pre,0,sizeof pre);
		memset(nodenum,0,sizeof nodenum);
		pre[1]=1;dfs(1);
		for(int i=1;i<=n;i++){
			bool flag=false;
			for(edge*j=head[i];j;j=j->next){
				int v=j->dest;
				if(v!=pre[i])
					if(nodenum[v]>n/2){
						flag=true;
						break;
					}
			}
			if(!flag&&n-nodenum[i]<=n/2)
				printf("%d\n",i);
		}
	}
	return 0;
}