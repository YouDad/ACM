#include<string.h>
//////////////////////////////////////
//名字:按花费规划的多重背包
//参数:花费数组 价值数组 个数数组 物品种数 最大花费
//返回值:在最大花费的情况下的最大价值
//注:dp[i]=j  花费至多为i的最大价值为j
//!cva数组从1开始!
//////////////////////////////////////
int MultiplePack(int Cost[],int Value[],int Amount[],int KindNumber,int MaxCost)
{
    int*dp=new int[MaxCost+1];
    memset(dp,0,4*MaxCost+4);
    for(int i=1;i<=KindNumber;i++)
    {
        if(Cost[i]*Amount[i]>=MaxCost)
        {
            for(int j=Cost[i];j<=MaxCost;j++)
                if(dp[j]<dp[j-Cost[i]]+Value[i])
                    dp[j]=dp[j-Cost[i]]+Value[i];
            continue;
        }
        int k=1;
        while(k<Amount[i])
        {
            for(int j=MaxCost;j>=k*Cost[i];j--)
                if(dp[j]<dp[j-k*Cost[i]]+k*Value[i])
                    dp[j]=dp[j-k*Cost[i]]+k*Value[i];
            Amount[i]-=k;
            k*=2;
        }
        for(int j=MaxCost;j>=Amount[i]*Cost[i];j--)
            if(dp[j]<dp[j-Amount[i]*Cost[i]]+Amount[i]*Value[i])
                dp[j]=dp[j-Amount[i]*Cost[i]]+Amount[i]*Value[i];
    }
    return dp[MaxCost];
}