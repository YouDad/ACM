// ////////////////////////////////////
// //有N件物品和一个容量为V的背包
// //第i件物品的费用是Cost[i]
// //价值是Value[i]
// //求解将哪些物品装入背包可使价值总和最大
// ////////////////////////////////////
// #include<string.h>
// //////////////////////////////////////
// //名字:按花费规划的01背包
// //参数:花费数组 价值数组 物品种数 最大花费
// //返回值:在最大花费的情况下的最大价值
// //注:dp[i]=j  花费至多为i的最大价值为j
// //!cv数组从1开始!
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
// //名字:按价值规划的01背包
// //参数:花费数组 价值数组 物品种数 最大价值
// //返回值:在最大价值的情况下的最小花费
// //注:dp[i]=j  价值至多为i的最小花费为j
// //!cv数组从1开始!
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