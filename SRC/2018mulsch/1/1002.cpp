#include<stdio.h>
#include<string.h>
#include<algorithm>
struct node{int l,r;}pair[100005];
inline int min(int a,int b){return a<b?a:b;}
/*nc*/inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
/*cini*/int ch,res;
int cini(){
    while((ch=nc())<'0'||ch>'9');res=ch-'0';
    while((ch=nc())>='0'&&ch<='9')res=res*10+ch-'0';
    return res;
}
int main(){
    int t=cini();
    while(t--){
        int n=cini(),ans=0;
        for(int i=0;i<n;i++){
            for(char p=nc();~p&&p!='\n';p=nc())
                if(p=='(')
                    pair[i].r++;
                else if(pair[i].r)
                    pair[i].r--,ans+=2;
                else
                    pair[i].l++;
        }std::sort(pair,pair+n,[](node a,node b){
            return a.l<a.r?(b.l<b.r?a.l<b.l:1):(b.l<b.r?0:a.r>b.r);
        });
        int l=0,r=0,tmp;
        for(int i=0;i<n;i++){
            tmp=min(r,pair[i].l);
            ans+=tmp*2;
            l+=pair[i].l-tmp;
            r+=pair[i].r-tmp;
        }
        memset(pair,0,n*8);
        printf("%d\n",ans);
    }
    return 0;
}