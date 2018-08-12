#include<stdio.h>
int abs(int x){return x<0?-x:x;}
int main(){
    int n,h,a,b,k;
    scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
    int ts,fs,te,fe;
    while(k--){
        scanf("%d%d%d%d",&ts,&fs,&te,&fe);
        if(fe>b&&fs>b&&ts!=te)
            printf("%d\n",abs(ts-te)+fe+fs-2*b);
        else if(fe<a&&fs<a&&ts!=te)
            printf("%d\n",abs(ts-te)+2*a-fe-fs);
        else
            printf("%d\n",abs(ts-te)+abs(fs-fe));
    }
    return 0;
}