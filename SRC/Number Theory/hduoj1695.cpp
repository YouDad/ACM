#include<stdio.h>
#include<algorithm>
const int maxn=100005;
int miu[maxn],prime[maxn];
bool vis[maxn];
int cnt,*smiu;
int min(int a,int b){return a<b?a:b;}
void init(){
    miu[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            miu[i]=-1;
        }
        for(int j=0;j<cnt&&i*prime[j]<maxn;j++){
            vis[i*prime[j]]=true;
            if(i%prime[j])
                miu[i*prime[j]]=-miu[i];
            else
                break;

        }
    }
    smiu=miu;
    for(int i=2;i<maxn;i++)
        smiu[i]+=smiu[i-1];
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    init();
    int t;scanf("%d",&t);
    for(int kase=1;t--;kase++){
        printf("Case %d: ",kase);
        int x,y,k;
        scanf("%*d%d%*d%d%d",&x,&y,&k);
        if(k==0){
            puts("0");
            continue;
        }
        x/=k;y/=k;
        if(x>y)x^=y^=x^=y;
        long long ans1=0,ans2=0,i,j;
        for(i=(j=0)+1;i<=x;i=j+1){
            j=min(x/(x/i),y/(y/i));
            ans1+=(smiu[j]-smiu[i-1])*(x/i)*(y/i);
        }
        for(i=(j=0)+1;i<=x;i=j+1){
            j=x/(x/i);
            ans2+=(smiu[j]-smiu[i-1])*(x/i)*(x/i);
        }
        printf("%lld\n",ans1-ans2/2);
    }
    return 0;
}