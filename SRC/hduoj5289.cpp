#include<bits/stdc++.h>
const int maxn=1e5+5;
int a[maxn];
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
		std::deque<int>max,min;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		int p=0,q=0;
		long long ans=0;
		while(p!=n||q!=n){
			if(q!=n){
				while(max.size()&&max.back()<a[q])max.pop_back();max.push_back(a[q]);
				while(min.size()&&min.back()>a[q])min.pop_back();min.push_back(a[q]);
			}
			while(q==n||max.front()-min.front()>=k){
				ans+=q-p;
				if(max.front()==a[p])max.pop_front();
				if(min.front()==a[p])min.pop_front();
				if(++p==n)break;
			}
			if(q!=n)q++;
		}
		printf("%lld\n",ans);
    }
    return 0;
}