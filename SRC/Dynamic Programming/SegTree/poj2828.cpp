#include<stdio.h>
#include<ctype.h>
int ch,res;
int cini(){
    while((ch=getchar())<'0'||ch>'9');
    res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9' )
        res=res*10+ch-'0';
    return res;
}
void out(int x){
    if(x>9)out(x/10);
    putchar(x%10+'0');
}
int ans[200005],arr[1<<19],pos[200005],val[200005];
int main(){
    for(int n;~scanf("%d",&n);){
        for(int i=0;i<n;i++)
            pos[i]=cini(),val[i]=cini();
        int M=1;while(M-2<n)M<<=1;
        for(int i=M+1;i<=M+n;i++)arr[i]=1;
        for(int i=M-1;i>0;i--)
            arr[i]=arr[i<<1]+arr[i<<1|1];
        for(int i=n-1;i>=0;i--){
            int p=1,x=pos[i]+1;arr[p]--;
            while(p<M){
                if(x>arr[p*=2])
                    x-=arr[p++];
                arr[p]--;
            }
            ans[p-=M]=val[i];
        }
        for(int i=1;i<=n;i++)
            out(ans[i]),putchar(" \n"[i==n]);
    }
    return 0;
}