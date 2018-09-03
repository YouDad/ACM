#include<stdio.h>
#include<vector>
#include<set>
using std::vector;
struct pair{
    int u,v;
    pair(int a=0,int b=0){u=a;v=b;}
    bool operator<(const pair&other)const{
        return u==other.u?v<other.v:u<other.u;
    }
};
#define degreedec(id) s.erase(pair(degree[id],id)),\
                      s.insert(pair(--degree[id],id))
#define foreach(it,obj)\
    for(auto it=obj.begin();it!=obj.end();it++)
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<pair>e(m+1);
    vector<int>ans(m+1),degree(n+1);
    vector<vector<pair>>adj(n+1);
    std::set<pair>s;
    vector<bool>ins(n+1,true);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&e[i].u,&e[i].v);
        adj[e[i].u].push_back(pair(e[i].v,i));
        adj[e[i].v].push_back(pair(e[i].u,i));
        degree[e[i].u]++;degree[e[i].v]++;
    }
    for(int i=1;i<=n;i++)
        s.insert(pair(degree[i],i));
    auto delete_node=[&](int i){
        while(s.size()&&s.begin()->u<k){
            int id=s.begin()->v;
            foreach(it,adj[id]){
                if(it->v>=i)
                    continue;
                if(ins[it->u])
                    degreedec(it->u);
            }
            s.erase(pair(degree[id],id));
            ins[id]=false;
        }
    };
    delete_node(m+1);
    for(int i=m;i;i--){
        ans[i]=s.size();
        int u=e[i].u,v=e[i].v;
        if(ins[u]&&ins[v]){
            degreedec(u);
            degreedec(v);
            delete_node(i);
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}