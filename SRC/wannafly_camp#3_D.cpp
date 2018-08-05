//neuqoj2079
#include<stdio.h>
#include<algorithm>
int a[1005];
int main(){
    int n,m,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int min=0,b;
        for(int i=0;i<n;i++){
            scanf("%d%d",a+i,&b);
            min+=b;
        }
        min=min<m?min:m;
        std::sort(a,a+n,[](int a,int b){return a>b;});
        int half=0,sum=0;
        for(int i=0;i<min;i++)
            half+=a[i];
        for(int i=min;i<n;i++)
            sum+=a[i];
        printf("%d.%d\n",half/2+sum,half%2*5);
    }
    return 0;
}