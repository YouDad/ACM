#include<stdio.h>
inline int max(int a,int b){return a>b?a:b;}
int arr[1<<19];
int main(){
    for(int h,w,n;~scanf("%d%d%d",&h,&w,&n);){
        int M=1;while(M-2<n)M<<=1;
        for(int i=1;i<=M+n;i++)arr[i]=w;
        for(int i=0,q;i<n;i++){
            scanf("%d",&q);
            int l=1,r=n,p=M+h+1;
            for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
                if(~l&1)if(arr[l^1]>=q){
                    w=l^1;while(w<M)w=w*2+(arr[w<<1]<q);
                    if(p>w)p=w;
                }
                if( r&1)if(arr[r^1]>=q){
                    w=r^1;while(w<M)w=w*2+(arr[w<<1]<q);
                    if(p>w)p=w;
                }
            }
            if(p-M<=h){
                printf("%d\n",p-M);
                for(arr[p]-=q,p>>=1;p;p>>=1)
                    arr[p]=max(arr[p<<1],arr[p<<1|1]);
            }else puts("-1");
        }
    }
    return 0;
}