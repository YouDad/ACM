//#include<stdio.h>
//long long cinl()
//{
//    long long res=0;
//    int ch,flag=0;
//    if((ch=getchar())=='-')
//        flag=1;
//    else if(ch>='0'&&ch<='9')
//        res=ch-'0';
//    while((ch=getchar())>='0'&&ch<='9' )
//        res=res*10+ch-'0';
//    return flag?-res:res;
//}
//long long cinl()//正数
//{
//	int ch;
//	while((ch=getchar())<'0'||ch>'9');
//	long long res=ch-'0';
//	while((ch=getchar())>='0'&&ch<='9' )
//		res=res*10+ch-'0';
//	return res;
//}
//int cinx()
//{
//	int ret=0;
//	int ch;
//	while((ch=getchar())>='0'&&ch<='9'||ch>='A'&&ch<='F')
//		if(ch>='0'&&ch<='9')
//			ret=ret*16+ch-'0';
//		else
//			ret=ret*16+ch-'A'+10;
//	return ret;
//}
//int cini()
//{
//    return (int)cinl();
//}
//double cind()
//{
//	double res=0;
//	int ch,flag=0;
//	if((ch=getchar())=='-')
//        flag=1;
//    else if(ch>='0'&&ch<='9')
//        res=ch-'0';
//	while((ch=getchar())>='0'&&ch<='9')
//        res=res*10+ch-'0';
//	int doc=0;
//	if(ch=='.')
//		while((ch=getchar())>='0'&&ch<='9')
//			res=res*10+ch-'0',doc++;
//	while(doc--)
//		res/=10;
//    return flag?-res:res;
//}
//double cinf()
//{
//	return (float)cind();
//}
//void coutl(long long num)
//{
//	if(num<0)
//		putchar('-'),num=-num;
//	long long ten=10;
//	while(num/ten)
//		ten*=10;
//	ten/=10;
//	while(num)
//	{
//		if(num/ten)
//			putchar((int)(num/ten)+'0'),num-=num/ten*ten;
//		else
//			putchar('0');
//		ten/=10;
//	}
//	if(num==0&&ten!=0)
//		while(ten)
//			putchar('0'),ten/=10;
//}
//void couti(int num)
//{
//	coutl(num);
//}
////void coutd(double num,double eps=1e-12)
////{
////	if(num<0)
////		putchar('-'),num=-num;
////	double ten=1.0;
////	while(num/ten>=1.0)
////		ten*=10.0;
////	while(num>eps)
////	{
////		if(ten==0.1)
////			putchar('.');
////		if(num/ten>=1.0)
////			putchar((int)(num/ten)+'0'),num-=(int)(num/ten)*ten;
////		ten/=10.0;
////	}
////}//精度不足