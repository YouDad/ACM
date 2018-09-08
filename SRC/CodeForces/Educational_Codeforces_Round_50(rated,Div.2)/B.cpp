#include<stdio.h>
int main(){
    int t;scanf("%d",&t);
    long long x,y,k;
    while(t--){
        scanf("%I64d%I64d%I64d",&x,&y,&k);
        if(x>k||y>k){
            puts("-1");
        }else if(x%2==y%2){
            if(x%2+k%2==1)
                printf("%I64d\n",k-2);
            else
                printf("%I64d\n",k);
        }else{
            printf("%I64d\n",k-1);
        }
    }
    return 0;
}