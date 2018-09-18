#include<stdio.h>
#include<string.h>
char s[1005],t[1005];
int next[1005],slen,tlen;
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(scanf("%s",s)&&s[0]!='#'){
        scanf("%s",t);
        slen=strlen(s);
        tlen=strlen(t);
        for(int i=1;i<=tlen;i++){
            int j=next[i];
            while(j&&t[i]!=t[j])j=next[j];
            next[i+1]=t[i]==t[j]?j+1:0;
        }
        int ans=0;
        for(int i=0,j=0;i<slen;i++){
            while(j&&s[i]!=t[j])j=next[j];
            if(s[i]==t[j])j++;
            if(j==tlen)ans++,j=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}