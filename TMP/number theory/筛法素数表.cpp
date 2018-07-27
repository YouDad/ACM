#include<memory.h>
#define MAX 100005
int prime[9600],prime_cnt=0;
bool isprime[MAX+1];
void init_prime()
{
   memset(isprime,true,sizeof(isprime));
   isprime[0]=isprime[1]=false;
   for(int i=2;i<=MAX;i++)
   {
       if(isprime[i])
           prime[prime_cnt++]=i;
       for(int j=0;j<prime_cnt&&prime[j]*i<=MAX;j++)
           isprime[prime[j]*i]=0;
   }
}
int primelistcnt[MAX],primelist[MAX][30];
void init_primelist()
{
    int i,x,k;
    memset(primelistcnt,0,sizeof(primelistcnt));
    for(i=2;i<MAX;i++)
    {
        k=i;
        for(x=0;prime[x]*prime[x]<=k;x++)
            if(k%prime[x]==0)
            {
                primelist[i][primelistcnt[i]++]=prime[x];
                while(k%prime[x]==0)
                k/=prime[x];
            }
        if(isprime[k])
            primelist[i][primelistcnt[i]++]=k;
    }
}