#include<stdio.h>
#include<string.h>
#include<algorithm>
struct idnode{
    int id,val;
}a[200005];
int arr[1<<19],M,x;
void update(int i,int val){
    for(arr[i]=val,i/=2;i;i/=2)
        arr[i]=std::min(arr[i*2],arr[i*2+1]);
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n,m,d;
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i].val),a[i].id=i;
    std::sort(a,a+n,[](idnode a,idnode b){return a.val<b.val;});
    for(M=1;M-2<n;M*=2);
    memset(arr,0x80,sizeof arr);
    arr[M]=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        for(x=1;x<M;)
            if(arr[x*2]+d<a[i].val)
                x=x*2;
            else
                x=x*2+1;
        update(x,a[i].val);
        a[i].val=x-M;
    }
    for(x=1;x<M;)
        if(arr[x*2]==0x80808080)
            x=x*2;
        else
            x=x*2+1;
    x-=M+1;
    printf("%d\n",x);
    std::sort(a,a+n,[](idnode a,idnode b){return a.id<b.id;});
    for(int i=0;i<n;i++)
        printf("%d%c",a[i].val," \n"[i==n-1]);
    return 0;
}