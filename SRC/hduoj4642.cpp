//这题充要必胜策略:如果右下角为1,先手一直翻右下角就赢!!
//否则先手输(先手随便翻什么,右下角就为1,对手获得必胜态!)
#include<stdio.h>
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);n*=m;
        for(int i=0;i<n;i++)
            scanf("%d",&m);
        puts(m?"Alice":"Bob");
    }
    return 0;
}