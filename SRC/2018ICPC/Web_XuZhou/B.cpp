// https://nanti.jisuanke.com/t/31454
#include<stdio.h>
#include<string.h>
typedef long long ll;
#define only(i,ending) (i==ending||i==2)
#define have(i,ending) (i==ending)
const int maxn=1005,good=1,normal=0,bad=-1;
struct node{int a,b,c;
    inline node(int a=0,int b=0,int c=0):a(a),b(b),c(c){}
}arr[maxn];
int rounds,initscore,goodend,badend;
int ending[maxn][201];
int dfs(int round,int score){
    if(score>+100)score=+100;
    if(score<-100)score=-100;
    if(round>rounds)
        return (score>=goodend)-(score<=badend);
    if(ending[round][score]!=0x3f3f3f3f)
        return ending[round][score];
    int res=0,a=2,b=2,c=2;
    if(arr[round].a)
        a=dfs(round+1,score+arr[round].a);
    if(arr[round].b)
        b=dfs(round+1,score-arr[round].b);
    if(arr[round].c)
        c=dfs(round+1,score*-1);
    if(round&1==1)//want good ending
        if(have(a,good)+have(b,good)+have(c,good))
            return ending[round][score]=good;
        else if(only(a,bad)*only(b,bad)*only(c,bad))
            return ending[round][score]=bad;
        else
            return ending[round][score]=normal;
    else
        if(have(a,bad)+have(b,bad)+have(c,bad))
            return ending[round][score]=bad;
        else if(only(a,good)*only(b,good)*only(c,good))
            return ending[round][score]=good;
        else
            return ending[round][score]=normal;
}
char ans[3][7]={"Bad","Normal","Good"};
int main(){
#ifdef LOCAL_DEBUG
	freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    while(~scanf("%d%d%d%d",&rounds,&initscore,&goodend,&badend)){
        memset(ending,0x3f,sizeof ending);
        for(int i=1;i<=rounds;i++)
            scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
        printf("%s Ending\n",ans[dfs(1,initscore)+1]);
    }
    return 0;
}