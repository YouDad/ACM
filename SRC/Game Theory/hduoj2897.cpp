#include<stdio.h>
//#include<set>
//int sg[1000];
//void solve(int p,int q){
//    memset(sg,0,sizeof sg);sg[0]=1;
//    for(int i=p+1;i<1000;i++){
//        std::set<int>s;
//        for(int j=p;j<=q;j++)
//            s.insert(sg[i-j]);
//        while(s.count(sg[i]))sg[i]++;
//    }
//}
int win(int n,int p,int q){
	return --n%(p+q)>=p;
}
int main(){
	//solve(3,20);//1,24,47,70
	int n,p,q;
	//freopen("1.txt","r",stdin);
	while(~scanf("%d%d%d",&n,&p,&q))
		puts(win(n,p,q)?"WIN":"LOST");
    return 0;
}