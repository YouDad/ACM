#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d",&k);
        printf("%d\n",k+4+(k>1));
    }
    return 0;
}