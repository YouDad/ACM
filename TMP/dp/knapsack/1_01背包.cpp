// ////////////////////////////////////
// //��N����Ʒ��һ������ΪV�ı���
// //��i����Ʒ�ķ�����Cost[i]
// //��ֵ��Value[i]
// //��⽫��Щ��Ʒװ�뱳����ʹ��ֵ�ܺ����
// ////////////////////////////////////
// #include<string.h>
// //////////////////////////////////////
// //����:�����ѹ滮��01����
// //����:�������� ��ֵ���� ��Ʒ���� ��󻨷�
// //����ֵ:����󻨷ѵ�����µ�����ֵ
// //ע:dp[i]=j  ��������Ϊi������ֵΪj
// //!cv�����1��ʼ!
// //////////////////////////////////////
// int ZeroOnePack_C(int Cost[],int Value[],int KindNumber,int MaxCost)
// {
// 	int*dp=new int[MaxCost+1];
// 	memset(dp,0,4*MaxCost);
// 	for(int i=1;i<=KindNumber;i++)
// 		for(int j=MaxCost;j>=Cost[i];j--)
// 			if(dp[j]<dp[j-Cost[i]]+Value[i])
// 				dp[j]=dp[j-Cost[i]]+Value[i];
// 	return dp[MaxCost];
// }
// //////////////////////////////////////
// //����:����ֵ�滮��01����
// //����:�������� ��ֵ���� ��Ʒ���� ����ֵ
// //����ֵ:������ֵ������µ���С����
// //ע:dp[i]=j  ��ֵ����Ϊi����С����Ϊj
// //!cv�����1��ʼ!
// //////////////////////////////////////
// int ZeroOnePack_V(int Cost[],int Value[],int KindNumber,int MaxValue)
// {
// 	int*dp=new int[MaxValue+1];
// 	dp[0]=0;memset(dp+1,0x3f3f3f3f,4*MaxValue);
// 	for(int i=1;i<=KindNumber;i++)
// 		for(int j=MaxValue;j>=Value[i];j--)
// 			if(dp[j]>dp[j-Value[i]]+Cost[i])
// 				dp[j]=dp[j-Value[i]]+Cost[i];
// 	return dp[MaxValue];
// }