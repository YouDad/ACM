#include<stdio.h>
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int h,m;double z;char c;
        scanf("%d %d UTC%c%lf",&h,&m,&c,&z);
        m+=h*60+6*((int)(z*10+0.1)*(c=='+'?1:-1)-80)+24*60;
        printf("%02d:%02d\n",m/60%24,m%60);
    }
    return 0;
}