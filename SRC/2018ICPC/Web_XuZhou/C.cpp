// https://nanti.jisuanke.com/t/31455
#include<stdio.h>
#include<string.h>
#include<algorithm>
int offer[]={0,0,0,0,0,0,
10000,36,720,360,80,252,
108,72,54,180,72,180,119,
36,360,1080,144,1800,3600};
const int select[3][8]={
    {0,3,6,0,1,2,0,2},
    {1,4,7,3,4,5,4,4},
    {2,5,8,6,7,8,8,6}
};
int number[10],sigma[10],cnt_sharp,cnt_star;
double ans_star,ans_sharp;
char map[5][5],mp[10],c;
bool vis[10];
#define stat(i,a,b,c) sigma[i]+=offer[number[a]+number[b]+number[c]]
int max(int a,int b){return a>b?a:b;}
void dfs_sharp(int x){
    if(x==9){
        for(int i=0;i<8;i++)
            stat(i,select[0][i],select[1][i],select[2][i]);
        cnt_sharp++;
        return;
    }
    if(!number[x]){
        for(int i=1;i<=9;i++){
            if(vis[i])continue;
            vis[i]=true;
            number[x]=i;
            dfs_sharp(x+1);
            number[x]=0;
            vis[i]=false;
        }
    }else dfs_sharp(x+1);
}
void dfs_star(int x){
    if(x==9){
        memset(sigma,0,sizeof sigma);
        cnt_sharp=ans_sharp=0;
        dfs_sharp(0);
        ans_sharp=*std::max_element(sigma,sigma+8);
        ans_star+=ans_sharp/cnt_sharp;
        cnt_star++;
        return;
    }
    if(mp[x]=='#')
        dfs_star(x+1);
    else if(mp[x]!='*')
        number[x]=mp[x]-'0',dfs_star(x+1);
    else{
        for(int i=1;i<=9;i++){
            if(vis[i])continue;
            vis[i]=true;
            number[x]=i;
            dfs_star(x+1);
            number[x]=0;
            vis[i]=false;
        }
    }
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d%*c",&t);
    while(t--){
        memset(number,0,sizeof number);
        memset(vis,false,sizeof vis);
        for(int i=0;i<3;i++){
            gets(map[i]);
            for(int j=0;j<3;j++){
                c=map[i][j];
                mp[i*3+j]=c;
                if('0'<=c&&c<='9')
                    vis[c-'0']=true;
            }
        }
        cnt_star=ans_star=0;
        dfs_star(0);
        printf("%.6lf\n",ans_star/cnt_star);
    }
    return 0;
}