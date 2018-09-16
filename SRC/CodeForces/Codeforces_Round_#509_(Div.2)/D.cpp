#include<stdio.h>
struct segment{
    int x,val;
}seg[200005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,h,sum=0;
    scanf("%d%d",&n,&h);
    for(int i=0;i<n;i++){
        scanf("%d%d",&seg[i].x,&seg[i].val);
        seg[i].val-=seg[i].x;
        seg[i].x-=sum;
        sum+=seg[i].val;
    }
    int thissum=0,maxsum=0;
    int l=0,r=0;
    while(l<n&&r<n){
        if(seg[r].x-seg[l].x<h){
            thissum+=seg[r].val;r++;
            if(thissum>maxsum)
                maxsum=thissum;
        }else{
            thissum-=seg[l].val;l++;
        }
    }
    printf("%d\n",h+maxsum);
    return 0;
}