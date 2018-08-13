//neuqoj2054
#include<stdio.h>
#define foreach for(int i=0;i<n;i++)for(int j=0;j<n;j++)
int a[1005][1005];
int main(){
    int n,x,y;
    while(~scanf("%d",&n)){
        foreach{
            scanf("%d",&a[i][j]);
        }
        foreach{
            if(a[i][j]==-1)x=i,y=j;
        }
        switch((x==0)*1+(y==0)*2){
            case 0://x!=0&&y!=0
                printf("%d\n",a[x-1][y]+a[x][y-1]
                -a[x-1][y-1]);break;
            case 1://x==0&&y!=0
                printf("%d\n",a[x+1][y]+a[x][y-1]
                    -a[x+1][y-1]);break;
            case 2://x!=0&&y==0
                printf("%d\n",a[x-1][y]+a[x][y+1]
                    -a[x-1][y+1]);break;
            case 3://x==0&&y==0
                printf("%d\n",a[x+1][y]+a[x][y+1]
                    -a[x+1][y+1]);break;
        }
    }
    return 0;
}