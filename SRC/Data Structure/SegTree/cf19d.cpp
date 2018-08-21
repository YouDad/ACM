#include<set>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
set<int,greater<int> >s[200005];
int arr[1<<19],x[200005],y[200005];
char op[200005];
int sorted[200005];
int main(){
    int n;scanf("%d%*c",&n);
    for(int i=0;i<n;i++)scanf("%c%*s %d %d%*c",op+i,x+i,y+i);
    memcpy(sorted,x,n*4);sort(sorted,sorted+n);
    int*sorted_end=unique(sorted,sorted+n);
    int sortlen=sorted_end-sorted;
    int M=1;while(M-2<sortlen)M*=2;
    for(int i=0;i<n;i++){
        int p=lower_bound(sorted,sorted_end,x[i])-sorted;
        if(op[i]=='f'){
            int l=p+1,r=sortlen,mp=r+M+1;//minpos
            for(l+=M-1,r+=M+1;l^r^1;l/=2,r/=2){
                if((~l&1)&&arr[l^1]>y[i])
                    for(int x=l^1;x<M||(mp=min(mp,x))&&false;)
                        x=x*2+(arr[x*2]<=y[i]);
                if(( r&1)&&arr[r^1]>y[i])
                    for(int x=r^1;x<M||(mp=min(mp,x))&&false;)
                        x=x*2+(arr[x*2]<=y[i]);
            }
            if(mp-M>sortlen)puts("-1");
            else{mp-=M;
                for(auto it=s[mp].crbegin();it!=s[mp].crend();it++)
                    if(*it>y[i]){printf("%d %d\n",sorted[mp],*it);break;}
            }
        }else{
            if(op[i]=='a'){
                s[p].emplace(y[i]);
                arr[p+M]=max(arr[p+M],y[i]);
            }else{
                for(auto it=s[p].begin();it!=s[p].end();it++)
                    if(*it==y[i]){s[p].erase(it);break;}
                arr[p+M]=0;if(!s[p].empty())arr[p+M]=*s[p].cbegin();
            }
            for(p=p+M>>1;p;p/=2)arr[p]=max(arr[p*2],arr[p*2+1]);
        }
    }
    return 0;
}