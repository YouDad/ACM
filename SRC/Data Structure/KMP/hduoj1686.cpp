#include<stdio.h>
#include<string.h>
char s[1000005],t[10005];
int next[10005],slen,tlen;
void getnext(char*t){
    for(int i=1;i<=tlen;i++){
        int j=next[i];
        while(j&&t[i]!=t[j])j=next[j];
        next[i+1]=t[i]==t[j]?j+1:0;
    }
}
int kcount(char*s,char*t){
    int ans=0;
    for(int i=0,j=0;i<slen;i++){
        while(j&&s[i]!=t[j])j=next[j];
        if(s[i]==t[j])j++;
        if(j==tlen)ans++;
    }return ans;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s%s",t,s);
        tlen=strlen(t);
        slen=strlen(s);
        getnext(t);
        printf("%d\n",kcount(s,t));
    }
    return 0;
}