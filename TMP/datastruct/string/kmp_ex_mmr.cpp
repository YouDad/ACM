//#include<string.h>
//#define maxn 1005
//int next[maxn];
//void getnext(char T[])
//{
//	int j=0,k=-1,tlen=strlen(T);
//	next[0]=-1;
//	while(j<tlen)
//		if(k==-1||T[j]==T[k])
//			next[++j]=++k;
//		else
//			k=next[k];
//}
//int kindex(char S[],char T[])//返回模式串T在主串S中首次出现的位置 返回的位置是从0开始的。
//{
//	int i=0, j=0;
//	getnext(T);
//	int slen=strlen(S);
//	int tlen=strlen(T);
//	while(i<slen&&j<tlen)
//		if(j==-1||S[i]==T[j])
//			i++,j++;
//		else
//			j=next[j];
//	if(j==tlen)
//		return i-tlen;
//	else
//		return -1;
//}
//int kcount(char S[],char T[])//返回模式串在主串S中出现的次数
//{
//	int ans=0;
//	int i,j=0;
//	int slen=strlen(S);
//	int tlen=strlen(T);
//	if(slen==1&&tlen==1)
//		if(S[0]==T[0])
//			return 1;
//		else
//			return 0;
//	getnext(T);
//	for(i=0;i<slen;i++)
//	{
//		while(j>0&&S[i]!=T[j])
//			j=next[j];
//		if(S[i]==T[j])
//			j++;
//		if(j==tlen)
//			ans++,
//			j=next[j];
//	}
//	return ans;
//}
//const int maxn=100010; //字符串长度最大值
//int next[maxn],ex[maxn]; //ex数组即为extend数组 ex[i]表示T与S[i,n-1]的最长公共前缀
////预处理计算next数组
//void getnext(char *str)
//{
//	int i=0,j,po,len=strlen(str);
//	next[0]=len;//初始化next[0]
//	while(str[i]==str[i+1]&&i+1<len)//计算next[1]
//		i++;
//	next[1]=i;
//	po=1;//初始化po的位置
//	for(i=2;i<len;i++)
//	{
//		if(next[i-po]+i<next[po]+po)//第一种情况，可以直接得到next[i]的值
//			next[i]=next[i-po];
//		else//第二种情况，要继续匹配才能得到next[i]的值
//		{
//			j=next[po]+po-i;
//			if(j<0)j=0;//如果i>po+next[po],则要从头开始匹配
//			while(i+j<len&&str[j]==str[j+i])//计算next[i]
//				j++;
//			next[i]=j;
//			po=i;//更新po的位置
//		}
//	}
//}
////计算extend数组
//void exkmp(char *S,char *T)
//{
//	int i=0,j,po,len=strlen(S),l2=strlen(T);
//	getnext(T);//计算子串的next数组
//	while(S[i]==T[i]&&i<l2&&i<len)//计算ex[0]
//		i++;
//	ex[0]=i;
//	po=0;//初始化po的位置
//	for(i=1;i<len;i++)
//	{
//		if(next[i-po]+i<ex[po]+po)//第一种情况，直接可以得到ex[i]的值
//			ex[i]=next[i-po];
//		else//第二种情况，要继续匹配才能得到ex[i]的值
//		{
//			j=ex[po]+po-i;
//			if(j<0)j=0;//如果i>ex[po]+po则要从头开始匹配
//			while(i+j<len&&j<l2&&S[j+i]==T[j])//计算ex[i]
//				j++;
//			ex[i]=j;
//			po=i;//更新po的位置
//		}
//	}
//}
//字符串的最小表示法,就是对于一个字符串,可以将它的最后一位放到第一位来,依次类推,一共有strlen种变形
//例如:s="00ab"
//变形有（省略引号）b00a ab00 0ab0 加上00ab 一共4种
//那么找到其中字典序最小的一个,用的算法便是minr,那么找到其中字典序最大的一个,用的算法便是maxr
//namespace
//{
//	bool mmr=false;
//}
//int minr(char s[])
//{
//	if(mmr==false)
//	{
//		memcpy(s+len,s,sizeof(char)*len);
//		s[len*2]=0;//array s must at least have double room
//		mmr=true;
//	}
//	int i=0,j=1;
//	while(i<len&&j<len)
//	{
//		int k=0;
//		while(s[i+k]==s[j+k]&&k<len)
//			k++;
//		if(k==len)
//			break;
//		if(s[i+k]>s[j+k])
//			i=i+k+1>j+1?i+k+1:j+1;
//		else
//			j=j+k+1>i+1?j+k+1:i+1;
//	}
//	return i<j?i:j;
//}
//int maxr(char s[])
//{
//	if(mmr==false)
//	{
//		memcpy(s+len,s,sizeof(char)*len);
//		s[len*2]=0;//array s must at least have double room
//		mmr=true;
//	}
//	int i=0,j=1;
//	while(i<len&&j<len)
//	{
//		int k=0;
//		while(s[i+k]==s[j+k]&&k<len)
//			k++;
//		if(k==len)
//			break;
//		if(s[i+k]<s[j+k])
//			i=i+k+1>j+1?i+k+1:j+1;
//		else
//			j=j+k+1>i+1?j+k+1:i+1;
//	}
//	return i<j?i:j;
//}