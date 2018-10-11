#include<stdio.h>
long long c[200005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,k,max=0;scanf("%d%d",&n,&k);
    for(int i=0,t;i<n;i++){
        scanf("%d",&t),c[t]++;
        if(t>max)max=t;
    }
    for(int i=max;i;i--)
        c[i-1]+=c[i];
    for(int i=1;i<=max;i++)
        c[i]+=c[i-1];
    int Ans=0,now=max;c[0]=c[1]-n;
    while(c[now]!=c[now-1]+n){
        int L=0,R=now,mid,ans;
        while(L<=R){
            mid=L+R>>1;
            if(c[now]-c[mid]<=k)
                ans=mid,R=mid-1;
            else L=mid+1;
        }Ans++;now=ans;
    }printf("%d\n",Ans);
    return 0;
}