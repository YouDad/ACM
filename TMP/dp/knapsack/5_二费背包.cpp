//#include<string.h>
////////////////////////////////////////
////����:�����Ѻ�����滮��01����
////����:�������� ������� ��ֵ���� ��Ʒ���� ��󻨷� ������
////����ֵ:����󻨷Ѻ�������������µ�����ֵ
////ע:dp[i][j]=k  ��������Ϊi�������Ϊj������ֵΪk
////!cvw�����1��ʼ!
////////////////////////////////////////
//int ZeroOnePack_2(int Cost[],int Volumn[],int Worth[],
//	int KindNumber,int MaxCost,int MaxVolumn)
//{
//	int**dp=new int*[MaxCost];
//	for(int i=0;i<=MaxCost;i++)
//		dp[i]=new int[MaxVolumn];
//	memset(dp,0,MaxCost*MaxVolumn*4);
//	for(int i=1;i<=KindNumber;i++)
//		for(int j=MaxCost;j>=Cost[i];j--)
//			for(int k=MaxVolumn;k>=Volumn[i];k--)
//				if(dp[j][k]<dp[j-Cost[i]][k-Volumn[i]]+Worth[i])
//					dp[j][k]=dp[j-Cost[i]][k-Volumn[i]]+Worth[i];
//	return dp[MaxCost][MaxVolumn];
//}
////////////////////////////////////////
////����:�����Ѻ�����滮����ȫ����
////����:�������� ������� ��ֵ���� ��Ʒ���� ��󻨷� ������
////����ֵ:����󻨷Ѻ�������������µ�����ֵ
////ע:dp[i][j]=k  ��������Ϊi�������Ϊj������ֵΪk
////!cvw�����1��ʼ!
////////////////////////////////////////
//int CompletePack_2(int Cost[],int Volumn[],int Worth[],
//	int KindNumber,int MaxCost,int MaxVolumn)
//{
//	int**dp=new int*[MaxCost];
//	for(int i=0;i<=MaxCost;i++)
//		dp[i]=new int[MaxVolumn];
//	memset(dp,0,MaxCost*MaxVolumn*4);
//	for(int i=1;i<=KindNumber;i++)
//		for(int j=Cost[i];j<=MaxCost;j++)
//			for(int k=Volumn[i];k<=MaxVolumn;k++)
//				if(dp[j][k]<dp[j-Cost[i]][k-Volumn[i]]+Worth[i])
//					dp[j][k]=dp[j-Cost[i]][k-Volumn[i]]+Worth[i];
//	return dp[MaxCost][MaxVolumn];
//}
//////////////////////////////////////////
//////����:�����Ѻ�����滮�Ķ��ر���
//////����:�������� ������� ��ֵ���� �������� ��Ʒ���� ��󻨷� ������
//////����ֵ:����󻨷Ѻ�������������µ�����ֵ
//////ע:dp[i][j]=k  ��������Ϊi�������Ϊj������ֵΪk
//////!cvwa�����1��ʼ!
//////////////////////////////////////////
//int MultiplePack_2(int Cost[],int Volumn[],int Worth[],int Amount[],
//	int KindNumber,int MaxCost,int MaxVolumn)
//{
//	int**dp=new int*[MaxCost];
//	for(int i=0;i<=MaxCost;i++)
//		dp[i]=new int[MaxVolumn];
//	memset(dp,0,MaxCost*MaxVolumn*4);
//	for(int i=1;i<=KindNumber;i++)
//	{
//		if(Cost[i]*Amount[i]>=MaxCost)
//		{
//			for(int j=Cost[i];j<=MaxCost;j++)
//				for(int k=Volumn[i];j<=MaxVolumn;j++)
//					if(dp[j][k]<dp[j-Cost[i]][k-Volumn[i]]+Worth[i])
//						dp[j][k]=dp[j-Cost[i]][k-Volumn[i]]+Worth[i];
//			continue;
//		}
//		int l=1;
//		while(l<Amount[i])
//		{
//			for(int j=MaxCost;j>=l*Cost[i];j--)
//				for(int k=MaxVolumn;k>=l*Volumn[i];k--)
//					if(dp[j][k]<dp[j-l*Cost[i]][k-l*Volumn[i]]+l*Worth[i])
//						dp[j][k]=dp[j-l*Cost[i]][k-l*Volumn[i]]+l*Worth[i];
//			Amount[i]-=l;
//			l*=2;
//		}
//		for(int j=MaxCost;j>=Amount[i]*Cost[i];j--)
//			for(int k=MaxVolumn;k>=Amount[i]*Volumn[i];k--)
//				if(dp[j][k]<dp[j-Amount[i]*Cost[i]][k-Amount[i]*Volumn[i]]+Amount[i]*Worth[i])
//					dp[j][k]=dp[j-Amount[i]*Cost[i]][k-Amount[i]*Volumn[i]]+Amount[i]*Worth[i];
//	}
//	return dp[MaxCost][MaxVolumn];
//}