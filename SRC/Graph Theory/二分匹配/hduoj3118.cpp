#include<stdio.h>
#include<string.h>
int map[15][15];
int calc(int k,int n){
    int ret=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if((1&(k>>i))==(1&(k>>j)))
                ret+=map[i][j];
    return ret;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n,m,u,v;scanf("%d%d",&n,&m);
        memset(map,0,sizeof map);
        while(m--){
            scanf("%d%d",&u,&v);
            map[u][v]++;
            map[v][u]++;
        }
        int min=2e9,res;
        for(int i=1;i<1<<n;i++){
            res=calc(i,n);
            if(min>res)
                min=res;
        }
        if(min==2e9)
            min=0;
        printf("%d\n",min);
    }
    return 0;
}