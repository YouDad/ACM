#include<stdio.h>
#include<algorithm>
int a[200005];
int main(){
    int n,s;scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    std::sort(a,a+n);
    long long ans=0;
    int pos=std::lower_bound(a,a+n,s)-a;
    if(pos<=n/2)
        for(int i=n/2;i>=pos;i--)
            ans+=a[i]-s;
    else
        for(int i=n/2;i<pos;i++)
            ans+=s-a[i];
    printf("%I64d\n",ans);
    return 0;
}