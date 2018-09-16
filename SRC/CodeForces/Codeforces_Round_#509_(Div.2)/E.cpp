#include<stdio.h>
#include<stack>
const int maxn=1005;
int a[maxn],b[maxn];
std::stack<int>s[maxn];
int cnt[maxn];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%d%d",a+i,b+i);
    int have=1,need=1;
    int sum=0;
    for(int i=1;i<n;i++)
        if(a[i]!=n&&b[i]!=n)
            goto no;
        else if(a[i]==n)
            a[i]^=b[i]^=a[i]^=b[i];
    for(int i=1;i<n;i++)
        cnt[a[i]]++;
    for(int i=1;i<n;i++)
        if(cnt[i]>sum+i)
            goto no;
        else sum-=cnt[i];
    while(have<=n&&need<n){
        while(have<n&&cnt[have])have++;
        while(need<n&&cnt[need]==0)need++;
        if(need>=n)break;
        if(cnt[need]==1)
            s[need].push(need),need++;
        else
            s[need].push(have++),
            cnt[need]--;
    }
    puts("YES");
    for(int i=1;i<n;i++){
        int x=s[a[i]].top();s[a[i]].pop();
        if(s[a[i]].size())
            printf("%d %d\n",x,s[a[i]].top());
        else
            printf("%d %d\n",x,n);
    }
    return 0;
    no:puts("NO");
    return 0;
}