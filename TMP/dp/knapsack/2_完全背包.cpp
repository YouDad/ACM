//#include<string.h>
////////////////////////////////////////
////����:�����ѹ滮����ȫ����
////����:�������� ��ֵ���� ��Ʒ���� ��󻨷�
////����ֵ:����󻨷ѵ�����µ�����ֵ
////ע:dp[i]=j  ��������Ϊi������ֵΪj
////!cv�����1��ʼ!
////////////////////////////////////////
//int CompletePack(int Cost[],int Value[],int KindNumber,int MaxCost)
//{
//	int*dp=new int[MaxCost+1];
//	memset(dp,0,4*MaxCost);
//	for(int i=1;i<=KindNumber;i++)
//		for(int j=Cost[i];j<=MaxCost;j++)
//			if(dp[j]<dp[j-Cost[i]]+Value[i])
//				dp[j]=dp[j-Cost[i]]+Value[i];
//	return dp[MaxCost];
//}
////////////////////////////////////////
////����:�����ѹ滮�ļ�ֵ��1����ȫ����
////����:�������� ��Ʒ���� ��󻨷�
////����ֵ:����󻨷ѵ�����µ�����ֵ
////ע:dp[i]=j  ��������Ϊi������ֵΪj
////	ÿ����Ʒ��ֵ��1
////!Cost�����1��ʼ!
////////////////////////////////////////
//int CompletePack_ValueIs1(int Cost[],int KindNumber,int MaxCost)
//{
//	int*dp=new int[MaxCost+1];
//	memset(dp,0,4*MaxCost);
//	for(int i=1;i<=KindNumber;i++)
//		for(int j=Cost[i];j<=MaxCost;j++)
//			if(dp[j]<dp[j-Cost[i]]+1)
//				dp[j]=dp[j-Cost[i]]+1;
//	return dp[MaxCost];
//}