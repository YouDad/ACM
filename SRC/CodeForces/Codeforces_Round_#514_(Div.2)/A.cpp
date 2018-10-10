#include<stdio.h>
const int maxn=100005;
int t[maxn],len[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,l,a;
    scanf("%d%d%d",&n,&l,&a);
    for(int i=0;i<n;i++)
        scanf("%d%d",t+i,len+i);
    int last=0,ans=0;t[n]=l;
    for(int i=0;i<=n;i++){
        ans+=(t[i]-last)/a;
        last=t[i]+len[i];
    }printf("%d\n",ans);
    return 0;
}