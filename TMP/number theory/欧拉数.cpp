//#define eunum 100000
//long long eu[eunum];
//void getEuler()
//{
//	for(int i=0;i<eunum;i++)
//		eu[i]=i;
//	for(int i=2;i<eunum;i++)
//		if(eu[i]==i)
//			for(int j=i;j<eunum;j+=i)
//				eu[j]=eu[j]/i*(i-1);
//}
//long long phi(long long n)
//{
//	long long res=n;
//	for(long long i=2;i*i<=n;i++)
//	{
//		if(n%i==0)
//		{
//			res/=i;
//			res*=i-1;
//			while(n%i==0)
//				n/=i;
//		}
//	}
//	if(n>1)
//	{
//		res/=n;
//		res*=n-1;
//	}
//	return res;
//}