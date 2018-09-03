#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
const int maxn=200005;
struct edge{
    int v;
    struct edge*next;
}e[maxn*2],*head[maxn];
int cnt,a[maxn];
void addedge(int u,int v){
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=e+cnt++;
    e[cnt].v=u;
    e[cnt].next=head[v];
    head[v]=e+cnt++;
}
bool vis[maxn];
int main(){
    int n,c=1,d=0;scanf("%d",&n);
    for(int i=1,u,v;i<n;i++)
        scanf("%d%d",&u,&v),
        addedge(u,v);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    if(a[0]!=1)goto No;
    while(d!=n){
        int u=a[d++];vis[u]=true;
        std::vector<int>v,w;
        for(edge*i=head[u];i;i=i->next)
            if(!vis[i->v])
                v.push_back(i->v),
                w.push_back(a[c++]);
        std::sort(v.begin(),v.end());
        std::sort(w.begin(),w.end());
        if(v!=w)goto No;
    }
	puts("Yes");return 0;
    No:puts("No");return 0;
}