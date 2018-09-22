#include<stdio.h>
#include<algorithm>
#include<set>
int cnt[15000005];
std::set<int>s;
int a[300005];
int prime[600],prime_cnt=0;
bool isprime[4001];
void init_prime(){
   for(int i=2;i<=4000;i++){
       if(!isprime[i])
           prime[prime_cnt++]=i;
       for(int j=0;j<prime_cnt&&prime[j]*i<=4000;j++)
           isprime[prime[j]*i]=true;
   }
}
void findfac(int num){
    for(int i=0;i<prime_cnt;i++){
        if(num%prime[i]==0){
            cnt[i]++;
            while(num%prime[i]==0)
                num/=prime[i];
        }
    }
    if(num!=1)
        s.insert(num),
        cnt[num]++;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    init_prime();
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    int g=a[0];
    for(int i=1;i<n;i++)
        g=std::__gcd(g,a[i]);
    for(int i=0;i<n;i++)
        findfac(a[i]/g);
    int max=-1;
    for(int i=0;i<prime_cnt;i++)
        if(cnt[i]&&max<cnt[i])
            max=cnt[i];
    for(auto it=s.begin();it!=s.end();it++)
        if(max<cnt[*it])
            max=cnt[*it];
    printf("%d\n",~max?n-max:-1);
    return 0;
}