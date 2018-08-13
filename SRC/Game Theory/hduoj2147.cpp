#include<string.h>
#include<stdio.h>
bool win[2005][2005];
void solve(){
    memset(win,false,sizeof win);
	for(int i=1;i<=2000;i++)
		for(int j=1;j<=2000;j++)
			if(!win[i][j])
				win[i][j+1]=win[i+1][j+1]=win[i+1][j]=true;
}
int main(){
    solve();
    int n,m;
    while(scanf("%d%d",&n,&m)&&n+m)
        puts(win[n][m]?"Wonderful!":"What a pity!");
    return 0;
}