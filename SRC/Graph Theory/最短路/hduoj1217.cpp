#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
double dist[35][35];
std::map<std::string,int>map;
int main(){
    for(int n,m,kase=1;scanf("%d",&n)&&n;kase++){
        printf("Case %d: ",kase);
        map.clear();
        for(int i=0;i<35;i++)
            for(int j=0;j<35;j++)
                dist[i][j]=i==j;
        std::string a,b;double c;
        for(int i=0;i<n;i++)
            std::cin>>a,map[a]=i;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
            std::cin>>a>>c>>b,
            dist[map[a]][map[b]]=c;
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(dist[i][j]<dist[i][k]*dist[k][j])
                        dist[i][j]=dist[i][k]*dist[k][j];
        for(int i=0;i<n;i++)
            if(dist[i][i]>1.0)
                goto Yes;
        No:puts("No");continue;
        Yes:puts("Yes");
    }
    return 0;
}