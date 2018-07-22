//int exgcd(int a,int b,int&x,int&y)
//{//ax+by=gcd(a,b)
//	if(b==0)
//	{
//		x=1,y=0;
//		return a;
//	}
//	int d=exgcd(b,a%b,y,x);
//	y-=a/b*x;
//	return d;
//}
//int axbyd(int a,int&x,int b,int&y,int d)
//{//ax+by=d
//	int gcd=exgcd(a,b,x,y);
//	if(d%gcd)
//		return 0;
//	x*=d/gcd;
//	y*=d/gcd;
//	return gcd;
//}