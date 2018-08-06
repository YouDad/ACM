//neuqoj2076
#include<stdio.h>
int m[4][4]={0,3,2,3,3,2,1,2,2,1,4,3,3,2,3,2};
int func(int x,int y){
    if(x>y){
        int t=x;
        x=y;y=t;
    }
    if(x<4&&y<4)
        return m[x][y];
    else if(y<=2*x+1)
        return (x+y)/6*2+(x+y)%2+(x+y)%6/5*2+((x+y)%6>=2&&(x+y)%2==0)*2;
    else
        return (y-x*2-2)/4*2+x+2+(y-2)%4%2;

}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",func(x<0?-x:x,y<0?-y:y));
    }
    return 0;
}