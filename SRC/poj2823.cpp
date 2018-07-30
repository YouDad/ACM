#include<queue>
#include<stdio.h>
const int maxn=1e6+5;
int a[maxn],min[maxn],max[maxn],cnt;
int main(){
    int n,k,t;
    while(~scanf("%d%d",&n,&k)){
        cnt=0;
        //单调队列内保存的是单调元素的下标
        std::deque<int>qmin,qmax;
        for(int i=0;i<n;i++){
            //清理非区间内的
            if(qmin.size()&&qmin.front()<=i-k)qmin.pop_front();
            if(qmax.size()&&qmax.front()<=i-k)qmax.pop_front();
            scanf("%d",&t);a[cnt++]=t;
            //保证队列单调
            while(qmin.size()&&a[qmin.back()]>=t)qmin.pop_back();qmin.push_back(i);
            while(qmax.size()&&a[qmax.back()]<=t)qmax.pop_back();qmax.push_back(i);
            //记录最值答案
            min[i]=a[qmin.front()];
            max[i]=a[qmax.front()];
        }
        for(int i=k-1;i<n;i++)
            printf("%d%s",min[i],i==n-1?"\n":" ");
        for(int i=k-1;i<n;i++)
            printf("%d%s",max[i],i==n-1?"\n":" ");
    }
    return 0;
}