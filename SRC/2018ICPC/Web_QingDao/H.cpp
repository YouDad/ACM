#include<stdio.h>
#include<string.h>
char s[100005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d%*c",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        long long ans=0;
        for(int i=0;i<len;i++){
            long long sum=s[i]=='0'?2:1;
            if(i)sum+=i*(s[i]==s[i-1]?2:1);
            ans+=sum*(len-i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}