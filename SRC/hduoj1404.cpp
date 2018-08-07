#include<stdio.h>
#include<string.h>
bool win[1000005];
int ten[]={1,10,100,1000,10000};
int f(char*str){
	int n=0;
	for(char*p=str;*p;p++)
		n=n*10+*p-'0';
	return n;
}
void solve(int n){
	char s[15];sprintf(s,"%d",n);
	int len=strlen(s);
	for(int i=0;i<len;i++){//每一位可以增加的
		char tmp=s[i];
		for(s[i]++;s[i]<='9';s[i]++)
			win[f(s)]=true;
		s[i]=tmp;
	}
	int base=1;
	while(len<6){//后面添上一个0和其他数字
		n*=10;len++;
		for(int i=0;i<base;i++)
			win[i+n]=1;
		base*=10;
	}
}
int main(){
	memset(win,false,sizeof win);win[0]=true;
	for(int i=1;i<1000000;i++)
		if(!win[i])solve(i);
	char s[15];
	while(~scanf("%s",s)){
		if(s[0]=='0'){
			puts("Yes");
			continue;
		}
		puts(win[f(s)]?"Yes":"No");
	}
	return 0;
}