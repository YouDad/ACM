#include<stdio.h>
int s[1000005],t[10005];
int next[10005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int slen,tlen;
        scanf("%d%d",&slen,&tlen);
        for(int i=0;i<slen;i++)
            scanf("%d",s+i);
        for(int i=0;i<tlen;i++)
            scanf("%d",t+i);
        for(int i=1;i<=tlen;i++){
            int j=next[i];
            while(j&&t[i]!=t[j])j=next[j];
            next[i+1]=t[i]==t[j]?j+1:0;
        }
        for(int i=0,j=0;i<slen;i++){
            while(j&&s[i]!=t[j])j=next[j];
            j=s[i]==t[j]?j+1:0;
            if(j==tlen){
                printf("%d\n",i-j+2);
                goto yes;
            }
        }
        puts("-1");
        yes:continue;
    }
    return 0;
}