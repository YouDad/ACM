#define bin(L,R,mid,condition,ret) {    \
    int l=L,r=R;                        \
    while(l<=r){                        \
        int mid=(long long)l+r>>1;      \
        if(condition)ret=mid,r=mid-1;   \
        else l=mid+1;                   \
    }                                   \
}//bin(ans,1,2e9,x,k<=calc(x),ans);