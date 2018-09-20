#include<stdio.h>
int cnt[105],a[105];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),cnt[a[i]]++;
    int nice=0;
    for(int i=0;i<105;i++)
        nice+=cnt[i]==1;
    if(nice%2){
        int can=-1;
        for(int i=0;i<105;i++)
            if(cnt[a[i]]>2){
                can=i;
                break;
            }
        if(~can){
            puts("YES");
            for(int i=0;i<n;i++)
                if(i==can)
                    putchar('A');
                else if(cnt[a[i]]==1&&nice>1)
                    putchar('A'),nice-=2;
                else
                    putchar('B');
        }else{
            puts("NO");
        }
    }else{
        puts("YES");
        for(int i=0;i<n;i++)
            if(cnt[a[i]]==1&&nice)
                putchar('A'),nice-=2;
            else
                putchar('B');
        putchar('\n');
    }
    return 0;
}