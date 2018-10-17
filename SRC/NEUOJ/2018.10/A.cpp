#include<stdio.h>
#include<string.h>
#include<algorithm>
char a[55],b[55];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%s%s",a,b)){
        int len=strlen(a),i=0,j=0,ans=0;
        std::sort(a,a+len);
        std::sort(b,b+len);
        for(;i<len&&j<len;)
        for(;j<len;j++)
        if(b[j]>=a[i]){
            ans+=b[j]-a[i++];
            b[j]=0;break;
        }
        for(i;i<len;)
        for(j=0;j<len;j++)
        if(b[j]){
            ans+=26+b[j]-a[i++];
        }printf("%d\n",ans);
    }
    return 0;
}