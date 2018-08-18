#include<stdio.h>
inline int max(int a,int b){return a>b?a:b;}
int arr[1<<19];
int main(){
    for(int n,m;~scanf("%d%d",&n,&m);){
        int M=1,a,b;while(M-2<n)M<<=1;
        for(int i=M+1;i<=M+n;i++)scanf("%d",arr+i);
        for(int i=M;i>0;i--)arr[i]=max(arr[i<<1],arr[i<<1|1]);
        char op[2];while(m--){
            scanf("%s%d%d",op,&a,&b);
            if(op[0]=='Q'){
                int ans=0;
                for(a+=M-1,b+=M+1;a^b^1;a>>=1,b>>=1){
                    if(~a&1)ans=max(ans,arr[a^1]);
                    if( b&1)ans=max(ans,arr[b^1]);
                }
                printf("%d\n",ans);
            }
            else
                for(arr[a+=M]=b,a>>=1;a;a>>=1)
                    arr[a]=max(arr[a<<1],arr[a<<1|1]);
        }
    }
    return 0;
}