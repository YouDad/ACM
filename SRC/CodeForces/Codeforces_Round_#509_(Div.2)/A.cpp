#include<stdio.h>
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    int max=-1,min=1e9+1,x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x>max)max=x;
        if(x<min)min=x;
    }
    printf("%d\n",max-min-n+1);
    return 0;
}