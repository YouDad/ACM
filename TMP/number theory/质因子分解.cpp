#include<stdlib.h>
long long qmul_mod(long long a,long long b,long long c)
{
   long long ret=0;
   a%=c;
   b%=c;

   while(b)
   {
       if(b&1)
           ret=(ret+a)%c;

       a=(a+a)%c;
       b>>=1;
   }

   return ret;
}
long long qpow_mod(long long a,long long b,long long c)
{
   long long ret=1;
   a%=c;
   b%=c;

   while(b)
   {
       if(b&1)
           ret=qmul_mod(ret,a,c);

       a=qmul_mod(a,a,c);
       b>>=1;
   }

   return ret;
}
bool mrtest(long long n)
{
   if(n<2)
       return false;

   int small_prime[]= {2,3,5,7,11,13,17,19,23,29};

   for(int i=0; i<10; i++)
       if(n==small_prime[i])
           return true;
       else if(n%small_prime[i]==0)
           return false;

   long long xx=n-1,yy=0;

   while(xx%2==0)
       xx/=2,yy++;

   for(int i=0; i<20; i++)
   {
       long long x=xx,y=yy,a=qpow_mod(rand()%(n-1)+1,x,n),lasta=a;

       while(y--)
       {
           a=qmul_mod(a,a,n);

           if(a==1&&lasta!=1&&lasta!=n-1)
               return false;

           lasta=a;
       }

       if(a!=1)
           return false;
   }

   return true;
}
#include<vector>
long long gcd(long long a,long long b)
{
   long long t;
   a=a<0?-a:a;
   b=b<0?-b:b;

   while(b)
   {
       t=a%b;
       a=b;
       b=t;
   }

   return a;
}
#define factype std::vector<long long>
factype findfac(long long n)
{
   std::vector<long long>v;

   if(n==1||mrtest(n))
   {
       v.push_back(n);
       return v;
   }

   std::vector<long long>v1,v2;
   long long p=n;

   while(p>=n)
   {
       long long i=1,k=2,x=rand()%p,y=x,d;

       while(true)
       {
           x=(qmul_mod(x,x,p)+rand()%n)%p;
           d=gcd(y-x,p);

           if(d!=1&&d!=p)
           {
               p=d;
               break;
           }

           if(y==x)
               break;

           if(++i==k)
               y=x,k+=k;
       }
   }

   v1=findfac(p);
   v2=findfac(n/p);
   v.insert(v.end(),v1.begin(),v1.end());
   v.insert(v.end(),v2.begin(),v2.end());
   return v;
}