#include<string.h>
//////////////////////////////////////
//����:�����ѹ滮�Ķ��ر���
//����:�������� ��ֵ���� �������� ��Ʒ���� ��󻨷�
//����ֵ:����󻨷ѵ�����µ�����ֵ
//ע:dp[i]=j  ��������Ϊi������ֵΪj
//!cva�����1��ʼ!
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