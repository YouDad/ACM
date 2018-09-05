#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x,nim=0,n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            nim^=x;
        }
        for(int i=0;i<n-1;i++)
            scanf("%*d%*d");
        puts(nim?"Q":"D");
    }
    return 0;
}