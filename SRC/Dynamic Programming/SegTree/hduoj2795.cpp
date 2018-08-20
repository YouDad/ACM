#include<stdio.h>
#include<algorithm>
int arr[1<<19];
int main(){
    for(int h,w,m;~scanf("%d%d%d",&h,&w,&m);){
        int n=m<h?m:h,M=1;while(M-2<n)M<<=1;
        for(int i=1;i<=M+n;i++)arr[i]=w;arr[M]=0;
        while(m--){
            int q,p=1;scanf("%d",&q);
            while(p<M)p=p*2+(arr[p<<1]<q);
            if(arr[p]>=q&&p-M<=n){
                printf("%d\n",p-M);
                for(arr[p]-=q,p>>=1;p;p>>=1)
                    arr[p]=std::max(arr[p<<1],arr[p<<1|1]);
            }else puts("-1");
        }
    }
    return 0;
}