//https://www.nowcoder.com/acm/contest/161/B
#include<stdio.h>
int a[100005],sg[100005];
int main(){
    for(int i=0;1<<i<100005;i++){
        for(int j=1;j<<i<100005;j+=2)
            sg[j<<i]=i+1;
    }
    int n;scanf("%d",&n);
    int nim=0;
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
        nim^=sg[a[i]];
    if(nim){
        int ans=0;
        for(int i=0;i<n;i++){
            nim^=sg[a[i]];
            for(int j=1;j*j<=a[i];j++)
                if(a[i]%j==0){
                    if(j*j!=a[i])
                    if(nim==sg[a[i]-a[i]/j])ans++;
                    if(nim==sg[a[i]-j])ans++;
                }
            nim^=sg[a[i]];
        }printf("%d\n",ans);
    }else puts("0");
    return 0;
}