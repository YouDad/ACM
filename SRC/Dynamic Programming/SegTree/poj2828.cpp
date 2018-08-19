#include<stdio.h>
#include<string.h>
int ch,res;
int cini(){
    while((ch=getchar())<'0'||ch>'9');
    res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9' )
        res=res*10+ch-'0';
    return res;
}
int arr[1<<19],q[1<<18],need[1<<18],val[1<<18];
int main(){
    for(int n;~scanf("%d",&n);){
        memset(q,0,sizeof q);
        int M=1;while(M-2<n)M<<=1;
        for(int i=M+1;i<=M+n;i++)arr[i]=1;
        for(int i=M;i>0;i--)arr[i]=arr[i<<1]+arr[i<<1|1];
        for(int i=0;i<n;i++)need[i]=cini(),val[i]=cini();
        for(int i=n-1,p;i>=0;i--){
            for(p=1;p<M;)
                if(arr[p<<1]>=need[i])p=p<<1;
                else need[i]-=arr[p<<1],p=p<<1|1;
            for(q[1+p-M]=val[i],arr[p]--,p>>=1;p;p>>=1)
                arr[p]=arr[p<<1]+arr[p<<1|1];
        }
        for(int i=1;i<n;i++)printf("%d ",q[i]);
        printf("%d\n",q[n]);
    }
}