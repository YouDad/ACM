//neuqoj2060
#include<stdio.h>
int main(){
    int n;
    while(~scanf("%d",&n)){
        int t,max=0;
        while(n--){
            scanf("%d",&t);
            if(max<t)
                max=t;
        }
        printf("%d\n",max*2);
    }
    return 0;
}