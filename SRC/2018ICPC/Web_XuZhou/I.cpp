// https://nanti.jisuanke.com/t/31461
#include<stdio.h>
char s[1000005];
int abs(int x){return x<0?-x:x;}
int main(){
#ifdef LOCAL_DEBUG
	freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n;char c,*p;
        scanf("%d %c%*c",&n,&c);
        gets(s);
        int ans=0;
        for(p=s;*p;p++){
            if(*p!=c){
                ans+=1+(abs(*p++-c)>=10);
                break;
            }
        }
        ans+=2*(s-p+n);
        if(ans==0&&n)
            ans++;
        printf("%d\n",ans);
    }
    return 0;
}