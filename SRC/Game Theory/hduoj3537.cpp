#include<stdio.h>
#include<algorithm>
//#include<string.h>
//#include<set>
//int sg[105];
//void solve(){
//	memset(sg,0,sizeof sg);
//	for(int i=1;i<=100;i++){
//		std::set<int>s;
//		for(int j=0;j<i;j++){
//			for(int k=j;k<i;k++){
//				s.insert(sg[j]^sg[k]);
//			}
//		}
//		while(s.count(sg[i]))sg[i]++;
//	}
//	for(int i=1;i<=100;i++)
//		printf("(%d,%d)",i-1,sg[i]);
//}
int ssg(int x){
	int add=1;
	for(int i=1;i<=x;i<<=1)
		add=((i&x)?1:0)^add;
	return x*2+add;
}
int a[105];
int main(){
	//solve();
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		std::sort(a,a+n);
		int cnt=std::unique(a,a+n)-a,nim=0;
		for(int i=0;i<cnt;i++)
			nim^=ssg(a[i]);
		puts(nim?"No":"Yes");
	}
	return 0;
}