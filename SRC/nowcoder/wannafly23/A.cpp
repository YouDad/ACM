//https://www.nowcoder.com/acm/contest/161/A
#include<stdio.h>
#include<algorithm>
char s[1000005];
int arr[64],dp[1000005];
inline int min(int a,int b){return a<b?a:b;}
void update(int x,int v){
    for(arr[x+=32]+=v,x/=2;x;x/=2)
        arr[x]=min(arr[x*2],arr[x*2+1]);
}
int query(){
    int l=32,r=59,ans=0x3f3f3f3f;
    for(;l^r^1;l/=2,r/=2){
        if(~l&1)ans=min(ans,arr[l^1]);
        if( r&1)ans=min(ans,arr[r^1]);
    }return ans;
}
int main(){
    gets(s);
    int l=0,r=0;
    for(char*p=s;*p;p++,r++){
        update(*p-'a'+1,1);
        while(query())
            update(s[l]-'a'+1,-1),
            dp[l++]=r-l+1;
    }
    printf("%d\n",*std::min_element(dp,dp+l));
    return 0;
}