//#include<string.h>
////////////////////////////////////////
////名字:按花费规划的完全背包
////参数:花费数组 价值数组 物品种数 最大花费
////返回值:在最大花费的情况下的最大价值
////注:dp[i]=j  花费至多为i的最大价值为j
////!cv数组从1开始!
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
////名字:按花费规划的价值是1的完全背包
////参数:花费数组 物品种数 最大花费
////返回值:在最大花费的情况下的最大价值
////注:dp[i]=j  花费至多为i的最大价值为j
////	每件物品价值是1
////!Cost数组从1开始!
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