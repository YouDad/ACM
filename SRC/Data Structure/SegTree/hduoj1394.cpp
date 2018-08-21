#include<stdio.h>
#include<string.h>
int arr[1<<14],a[5005];
int main(){
    for(int n;~scanf("%d",&n);){
        int sum=0,l,r,M=1;while(M-2<n)M<<=1;
		memset(arr,0,sizeof arr);
		for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int t,i=0;i<n;i++){
            t=a[i],l=t+1,r=n;
            for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
                if(~l&1)sum+=arr[l^1];
                if( r&1)sum+=arr[r^1];
            }
            for(arr[t+=M]++,t>>=1;t;t>>=1)
                arr[t]=arr[t<<1]+arr[t<<1|1];
        }
        int min=sum;
        for(int i=0;i<n-1;i++)
            sum=sum-a[i]+n-1-a[i],
            min=min<sum?min:sum;
        printf("%d\n",min);
    }
    return 0;
}