#include<stdio.h>
int arr[1<<17];
int main(){
	int kase;scanf("%d",&kase);
    for(int k=1;k<=kase;k++){
        printf("Case %d:\n",k);
        int n,M=1;scanf("%d",&n);while(M-2<n)M<<=1;
        for(int i=M+1;i<=M+n;i++)scanf("%d",arr+i);
        for(int i=M;i>0;i--)arr[i]=arr[i<<1]+arr[i<<1|1];
        for(char str[6];scanf("%s",str)&&str[0]!='E';){
            int s,t,ans=0;scanf("%d%d",&s,&t);
            if(str[0]=='Q'){
                for(s=s+M-1,t=t+M+1;s^t^1;s>>=1,t>>=1){
                    if(~s&1)ans+=arr[s^1];
                    if( t&1)ans+=arr[t^1];
                }
                printf("%d\n",ans);
            }
            else
                for(arr[s+=M]+=t*(str[0]=='A'?1:-1),s>>=1;s;s>>=1)
                    arr[s]=arr[s<<1]+arr[s<<1|1];
        }
    }
    return 0;
}