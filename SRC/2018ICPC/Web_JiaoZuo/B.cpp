#include<stdio.h>
#include<string.h>
typedef long long ll;
const int maxn=1005,MAX=1,MIN=0;
ll max[maxn][6],min[maxn][6];
char s[7];int a[maxn];
void sel(int mode,ll&a,ll b){
    if(mode&&b>a)a=b;
    if(!mode&&b<a)a=b;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        scanf("%s",s+1);
        for(int i=0;i<maxn;i++)
            for(int j=0;j<6;j++)
                max[i][j]=-0x3f3f3f3f3f3f3f3f,
                min[i][j]=0x3f3f3f3f3f3f3f3f;
        max[0][0]=min[0][0]=k;
        for(int i=1;i<=n;i++){
            max[i][0]=min[i][0]=max[i-1][0];
            for(int j=1;j<=m&&j<=i;j++){
                switch(s[j]){
                    case '+':
                        sel(MAX,max[i][j],max[i-1][j]);
                        sel(MAX,max[i][j],max[i-1][j-1]+a[i]);
                        sel(MIN,min[i][j],min[i-1][j]);
                        sel(MIN,min[i][j],min[i-1][j-1]+a[i]);
                        break;
                    case '-':
                        sel(MAX,max[i][j],max[i-1][j]);
                        sel(MAX,max[i][j],max[i-1][j-1]-a[i]);
                        sel(MIN,min[i][j],min[i-1][j]);
                        sel(MIN,min[i][j],min[i-1][j-1]-a[i]);
                        break;
                    case '*':
                        sel(MAX,max[i][j],max[i-1][j]);
                        sel(MAX,max[i][j],max[i-1][j-1]*a[i]);
                        sel(MAX,max[i][j],min[i-1][j-1]*a[i]);
                        sel(MIN,min[i][j],min[i-1][j]);
                        sel(MIN,min[i][j],min[i-1][j-1]*a[i]);
                        sel(MIN,min[i][j],max[i-1][j-1]*a[i]);
                        break;
                    case '/':
                        sel(MAX,max[i][j],max[i-1][j]);
                        sel(MAX,max[i][j],max[i-1][j-1]/a[i]);
                        sel(MAX,max[i][j],min[i-1][j-1]/a[i]);
                        sel(MIN,min[i][j],min[i-1][j]);
                        sel(MIN,min[i][j],min[i-1][j-1]/a[i]);
                        sel(MIN,min[i][j],max[i-1][j-1]/a[i]);
                        break;
                }
            }
        }
        printf("%lld\n",max[n][m]);
    }
    return 0;
}