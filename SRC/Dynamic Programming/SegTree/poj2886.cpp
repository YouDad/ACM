#include<stdio.h>
#include<algorithm>
int anti[36]={
    1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,
    2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,
    55440,83160,110880,166320,221760,277200,332640,498960,554400
},fact[36]={
    1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,
    80,84,90,96,100,108,120,128,144,160,168,180,192,200,216
},val[500005],arr[1<<20];char name[500005][11];
int main(){
    for(int n,k;~scanf("%d%d",&n,&k);){
        for(int i=1;i<=n;i++)scanf("%s%d",name[i],val+i);
        int M=1;while(M-2<n)M<<=1;
        for(int i=M+1;i<=M+n;i++)arr[i]=1;
        for(int i=M;i>0;i--)arr[i]=arr[i<<1]+arr[i<<1|1];
        int*p=std::upper_bound(anti,anti+36,n)-1;
        int ans2=fact[p-anti],mod=n;n=*p;k--;
        for(int pos=0,x;n--;mod--){
            k=(k+val[pos]%mod-(val[pos]>0)+mod)%mod;
            for(x=k+1,pos=1;pos<M;)
                if(arr[pos<<1]>=x)pos=pos<<1;
                else x-=arr[pos<<1],pos=pos<<1|1;
            for(x=pos,pos-=M,arr[x]--,x>>=1;x;x>>=1)
                arr[x]=arr[x<<1]+arr[x<<1|1];
            if(!n)printf("%s %d\n",name[pos],ans2);
        }
    }
    return 0;
}