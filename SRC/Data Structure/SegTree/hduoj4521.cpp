#include<stdio.h>
#include<string.h>
#include<algorithm>
int arr[1<<18],seq[100005],dp[100005],M;
void update(int x,int val){x++;
    for(arr[x+=M]=std::max(arr[x],val),x/=2;x;x/=2)
        arr[x]=std::max(arr[x*2],arr[x*2+1]);
}
int query(int l,int r){l++,r++;
    if(l>r)return 0;int ans=0;
    for(l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
        if(~l&1)ans=std::max(ans,arr[l^1]);
        if( r&1)ans=std::max(ans,arr[r^1]);
    }return ans;
}
int main(){
    for(int n,d;~scanf("%d%d",&n,&d);){
        M=1;while(M-2<100000)M*=2;
        memset(arr,0,sizeof arr);
        for(int i=0;i<n;i++){
            scanf("%d",seq+i);
            dp[i]=query(0,seq[i]-1)+1;
            if(i>=d)update(seq[i-d],dp[i-d]);
        }printf("%d\n",*std::max_element(dp,dp+n));
    }return 0;
}