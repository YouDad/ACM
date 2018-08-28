#include<stdio.h>
#include<string.h>
#include<xfunctional>
#include<vector>
#include<queue>
int pre[100005],ans[100005];
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
        int n=cini(),m=cini(),pl=1;
		std::priority_queue<int,std::vector<int>,std::greater<int>>q;
		for(int i=1;i<=n;i++)q.push(i);
        for(int i=1;i<=n;i++)pre[i]=i;
        while(m--){
            int l=cini(),r=cini();
            pre[r]=min(pre[r],l);
        }
        for(int i=n-1;i>0;i--)pre[i]=min(pre[i],pre[i+1]);
        for(int i=1;i<=n;i++){
            while(pl<pre[i])
				q.push(ans[pl++]);
			ans[i]=q.top();q.pop();
        }
        for(int i=1;i<=n;i++)
            printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}