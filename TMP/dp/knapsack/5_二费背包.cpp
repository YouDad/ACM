//#include<string.h>
////////////////////////////////////////
////名字:按花费和体积规划的01背包
////参数:花费数组 体积数组 价值数组 物品种数 最大花费 最大体积
////返回值:在最大花费和最大体积的情况下的最大价值
////注:dp[i][j]=k  花费至多为i体积至多为j的最大价值为k
////!cvw数组从1开始!
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
////名字:按花费和体积规划的完全背包
////参数:花费数组 体积数组 价值数组 物品种数 最大花费 最大体积
////返回值:在最大花费和最大体积的情况下的最大价值
////注:dp[i][j]=k  花费至多为i体积至多为j的最大价值为k
////!cvw数组从1开始!
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
//////名字:按花费和体积规划的多重背包
//////参数:花费数组 体积数组 价值数组 个数数组 物品种数 最大花费 最大体积
//////返回值:在最大花费和最大体积的情况下的最大价值
//////注:dp[i][j]=k  花费至多为i体积至多为j的最大价值为k
//////!cvwa数组从1开始!
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