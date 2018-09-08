#include<stdio.h>
const int maxn=300005;
int a[maxn],b[maxn];
int max(int a,int b){return a>b?a:b;}
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int m;scanf("%d",&m);
    for(int i=0;i<m;i++)scanf("%d",b+i);
    long long s=a[0],t=b[0];
    int ans=0,i=1,j=1;
    while(i<n&&j<m){
        if(s==t)
            s=a[i++],t=b[j++],ans++;
        else if(s>t)
            t+=b[j++];
        else
            s+=a[i++];
    }
    while(i<n)s+=a[i++];
    while(j<m)t+=b[j++];
    if(s!=t)
        puts("-1");
    else
        printf("%d\n",ans+(s!=0));
    return 0;
}