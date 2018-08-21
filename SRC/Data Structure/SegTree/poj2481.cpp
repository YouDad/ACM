#include<stdio.h>
#include<string.h>
#include<algorithm>
struct input{int l,r,i;}in[100005];
int arr[1<<18],ans[100005];
/*cini*/int ch,res;
int cini(){
    while((ch=getchar())<'0'||ch>'9');res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-'0';
    return res;
}
/*out*/void out(int x){if(x>9)out(x/10);putchar(x%10+'0');}
bool cmp(input a,input b){return a.r==b.r?a.l<b.l:a.r>b.r;}
int main(){
    for(int n;n=cini();){
        for(int i=0;i<n;i++)
            in[i].l=cini()+1,in[i].r=cini()+1,in[i].i=i;
        std::sort(in,in+n,cmp);
        memset(arr,0,sizeof arr);
        memset(ans,0,sizeof ans);
        int M=1;while(M-2<n)M*=2;ans[in[0].i]=0;
        for(int x=in[0].l+M;x;x/=2)arr[x]=1;
        for(int i=1,l,r,x;i<n;i++){
            if(in[i].l==in[i-1].l&&in[i].r==in[i-1].r)
                ans[in[i].i]=ans[in[i-1].i];
            else
                for(l=M,r=in[i].l+M+1;l^r^1;l/=2,r/=2){
                    if(~l&1)ans[in[i].i]+=arr[l^1];
                    if( r&1)ans[in[i].i]+=arr[r^1];
                }
            for(x=in[i].l+M,arr[x]++,x/=2;x;x/=2)
                arr[x]=arr[x*2]+arr[x*2+1];
        }for(int i=0;i<n;i++)
            out(ans[i]),putchar(" \n"[i==n-1]);
    }return 0;
}