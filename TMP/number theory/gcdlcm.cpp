long long gcd(long long a,long long b)
{
    long long t;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}
long long lcm(long long x,long long y){return x/gcd(x,y)*y;}
//���ư浥������ģmod�����µĳ˷���Ԫ
//����:x
//���:inv(x)�����ķ���ֵ
#define mod 1
long long extgcd(long long a,long long b,long long& x,long long& y)
{
   long long d=a;
   if(b!=0)
       d=extgcd(b,a%b,y,x),
       y-=(a/b)*x;
    else
       x=1,
       y=0;
   return d;
}
long long inv(long long x)
{
   long long x,y;
   extgcd(x,mod,x,y);
   return (mod+x%mod)%mod;
}
//end