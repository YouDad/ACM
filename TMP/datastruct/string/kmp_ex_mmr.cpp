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
//int kindex(char S[],char T[])//����ģʽ��T������S���״γ��ֵ�λ�� ���ص�λ���Ǵ�0��ʼ�ġ�
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
//int kcount(char S[],char T[])//����ģʽ��������S�г��ֵĴ���
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
//const int maxn=100010; //�ַ����������ֵ
//int next[maxn],ex[maxn]; //ex���鼴Ϊextend���� ex[i]��ʾT��S[i,n-1]�������ǰ׺
////Ԥ�������next����
//void getnext(char *str)
//{
//	int i=0,j,po,len=strlen(str);
//	next[0]=len;//��ʼ��next[0]
//	while(str[i]==str[i+1]&&i+1<len)//����next[1]
//		i++;
//	next[1]=i;
//	po=1;//��ʼ��po��λ��
//	for(i=2;i<len;i++)
//	{
//		if(next[i-po]+i<next[po]+po)//��һ�����������ֱ�ӵõ�next[i]��ֵ
//			next[i]=next[i-po];
//		else//�ڶ��������Ҫ����ƥ����ܵõ�next[i]��ֵ
//		{
//			j=next[po]+po-i;
//			if(j<0)j=0;//���i>po+next[po],��Ҫ��ͷ��ʼƥ��
//			while(i+j<len&&str[j]==str[j+i])//����next[i]
//				j++;
//			next[i]=j;
//			po=i;//����po��λ��
//		}
//	}
//}
////����extend����
//void exkmp(char *S,char *T)
//{
//	int i=0,j,po,len=strlen(S),l2=strlen(T);
//	getnext(T);//�����Ӵ���next����
//	while(S[i]==T[i]&&i<l2&&i<len)//����ex[0]
//		i++;
//	ex[0]=i;
//	po=0;//��ʼ��po��λ��
//	for(i=1;i<len;i++)
//	{
//		if(next[i-po]+i<ex[po]+po)//��һ�������ֱ�ӿ��Եõ�ex[i]��ֵ
//			ex[i]=next[i-po];
//		else//�ڶ��������Ҫ����ƥ����ܵõ�ex[i]��ֵ
//		{
//			j=ex[po]+po-i;
//			if(j<0)j=0;//���i>ex[po]+po��Ҫ��ͷ��ʼƥ��
//			while(i+j<len&&j<l2&&S[j+i]==T[j])//����ex[i]
//				j++;
//			ex[i]=j;
//			po=i;//����po��λ��
//		}
//	}
//}
//�ַ�������С��ʾ��,���Ƕ���һ���ַ���,���Խ��������һλ�ŵ���һλ��,��������,һ����strlen�ֱ���
//����:s="00ab"
//�����У�ʡ�����ţ�b00a ab00 0ab0 ����00ab һ��4��
//��ô�ҵ������ֵ�����С��һ��,�õ��㷨����minr,��ô�ҵ������ֵ�������һ��,�õ��㷨����maxr
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