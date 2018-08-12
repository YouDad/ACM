#include<stdio.h>
int x[300005];
bool check(int z,int n){
    long long need=0,have=0;
    for(int i=0;i<n;i++)
        if(z>x[i])
            need+=z-x[i];
        else
            have+=(x[i]-z)/2;
    return have>=need;
}
int ch,res;
int cinl()//正数
{
    while((ch=getchar())<'0'||ch>'9');
    res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9' )
        res=res*10+ch-'0';
    return res;
}
int main(){
    int t=cinl();
    while(t--){
        int n=cinl();
        int min=1e8+1,max=0;
        for(int i=0;i<n;i++){
            x[i]=cinl();
            min=min<x[i]?min:x[i];
            max=max>x[i]?max:x[i];
        }
        while(max-min>=2){
            int mid=min+max>>1;
            if(check(mid,n))
                min=mid;
            else
                max=mid;
        }
        if(check(max,n))min=max;
        printf("%I64d\n",min);
    }
    return 0;
}