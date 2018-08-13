#include<stdio.h>
#include<string.h>
int p[1005];
bool vis[1005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof vis);
		int a=i;vis[a]=true;
		while(!vis[p[a]])
			vis[p[a]]=true,a=p[a];
		printf("%d%c",p[a],i==n?'\n':' ');
	}
	return 0;
}