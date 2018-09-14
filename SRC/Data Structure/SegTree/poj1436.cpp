#include<stdio.h>
#include<string.h>
#include<bitset>
#include<algorithm>
const int maxn=8005;
std::bitset<maxn>bs[maxn];
struct segment{
    int yl,yh,x,i;
    void set(int y1,int y2,int xx,int ii){
        yl=y1;yh=y2;x=xx;i=ii;
    }
    bool operator<(const segment&other)const{
        return x<other.x;
    }
}seg[maxn];
int arr[1<<15],M,ss[32],top;
bool lzdown(int u){
    if(u>M)u/=2;
    for(top=0;u;u/=2)ss[top++]=u;
    while(top--){
        if(arr[u=ss[top]]>0){
            arr[u*2]=arr[u];
            arr[u*2+1]=arr[u];
        }
    }
    return true;
}
void update(int l,int r,int c){l++,r++;
    int L=0,R=0;
    for(l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
        if(~l&1)if(L||(L=l^1))arr[l^1]=c;
        if( r&1)if(R||(R=r^1))arr[r^1]=c;
    }
    for(L/=2;L;L/=2)
        if(arr[L*2]==arr[L*2+1])
            arr[L]=arr[L*2];
        else arr[L]=-1;
    for(R/=2;R;R/=2)
        if(arr[R*2]==arr[R*2+1])
            arr[R]=arr[R*2];
        else arr[R]=-1;
}
void dfs(int u,int s){
    while(u<M){
        if(arr[u*2]==-1)
            dfs(u*2,s);
        else if(arr[u*2])
            bs[s].set(arr[u*2]),
            bs[arr[u*2]].set(s);
        if(arr[u*2+1]==-1)
            dfs(u*2+1,s);
        else if(arr[u*2+1])
            bs[s].set(arr[u*2+1]),
            bs[arr[u*2+1]].set(s);
        return;
    }
}
void query(int l,int r,int s){
    int L=0,R=0;l++,r++;
    for(l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
        if(~l&1)if(L||(lzdown(L=l^1)))
            if(arr[l^1]==-1)
                dfs(l^1,s);
            else if(arr[l^1])
                bs[s].set(arr[l^1]),
                bs[arr[l^1]].set(s);
        if( r&1)if(R||(lzdown(R=r^1)))
            if(arr[r^1]==-1)
                dfs(r^1,s);
            else if(arr[r^1])
                bs[s].set(arr[r^1]),
                bs[arr[r^1]].set(s);
    }
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        int yl,yh,x;
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&yl,&yh,&x),
            seg[i].set(yl,yh,x,i+1);
        std::sort(seg,seg+n);
        memset(arr,0,sizeof arr);M=1<<14;
        for(int i=0;i<maxn;i++)bs[i].reset();
        for(int i=0;i<n;i++){
            query(seg[i].yl*2,seg[i].yh*2,seg[i].i);
            update(seg[i].yl*2,seg[i].yh*2,seg[i].i);
        }
        int ans=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                if(bs[i][j])
                    for(int k=j+1;k<=n;k++)
                        ans+=bs[i][k]&&bs[j][k];
        printf("%d\n",ans);
    }
    return 0;
}