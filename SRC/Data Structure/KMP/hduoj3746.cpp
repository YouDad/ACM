#include<stdio.h>
#include<string.h>
char t[100005];
int next[100005],tlen;
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",t);
        tlen=strlen(t);
        for(int i=1;i<=tlen;i++){
            int j=next[i];
            while(j&&t[i]!=t[j])j=next[j];
            next[i+1]=t[i]==t[j]?j+1:0;
        }
        int cyc=tlen-next[tlen];
        if(cyc==tlen)
            printf("%d\n",cyc);
        else if(tlen%cyc==0)
            puts("0");
        else
            printf("%d\n",(tlen/cyc+1)*cyc-tlen);
    }
    return 0;
}