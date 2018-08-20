#include<set>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
set<int,greater<int> >s[200005];char op[200005];
int x[200005],y[200005],sorted[200005],arr[1<<19];
int main(){
    int n;scanf("%d%*c",&n);
    for(int i=0;i<n;i++)scanf("%c%*s %d %d%*c",op+i,x+i,y+i);
    memcpy(sorted,x,n*4);sort(sorted,sorted+n);
    int sortlen=unique(sorted,sorted+n)-sorted;
    int M=1;while(M-2<sortlen)M<<=1;
    for(int i=0;i<n;i++){
        int pos=lower_bound(sorted,sorted+sortlen,x[i])-sorted;
        if(op[i]=='f'){
            int l=pos+1,r=sortlen,mpos=sortlen+M+1;//minpos
            for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
                if((~l&1)&&arr[l^1]>y[i])
                    for(int p=l^1;p<M||(mpos=min(mpos,p));)
                        p=p*2+(arr[p<<1]<=y[i]);
                if(( r&1)&&arr[r^1]>y[i])
                    for(int p=r^1;p<M||(mpos=min(mpos,p));)
                        p=p*2+(arr[p<<1]<=y[i]);
            }
            if(mpos-M>sortlen)puts("-1");
            else
                for(auto it=s[mpos-=M].crbegin();it!=s[mpos].crend();it++)
                    if(*it>y[i]){printf("%d %d\n",sorted[mpos],*it);break;}
        }
        else{
            if(op[i]=='a'){
                s[pos].emplace(y[i]);
                arr[pos+M]=max(arr[pos+M],y[i]);
            }else if(op[i]=='r'){
                s[pos].erase(s[pos].begin());
                arr[pos+M]=0;
                if(!s[pos].empty())
                    arr[pos+M]=*s[pos].cbegin();
            }
            for(pos=pos+M>>1;pos;pos>>=1)
                arr[pos]=max(arr[pos<<1],arr[pos<<1|1]);
        }
    }
    return 0;
}