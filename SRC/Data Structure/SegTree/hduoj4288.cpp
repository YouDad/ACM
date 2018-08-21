#include<stdio.h>
#include<string.h>
#include<algorithm>
long long sum[1<<18][5];int cnt[1<<18],raw[1<<17],wash[1<<17];
char op[1<<17];
int main(){
    for(int n;~scanf("%d%*c",&n);){
        int M=1;while(M-2<n)M<<=1;
        for(int i=0;i<n;i++)
            if((op[i]=getchar())!='s')
                scanf("%*s %d%*c",raw+i);
            else scanf("%*s%*c");
        memcpy(wash,raw,n*4);
        memset(sum,0,sizeof sum);
        memset(cnt,0,sizeof cnt);
        std::sort(wash,wash+n+1);
        int len=std::unique(wash,wash+n+1)-wash;
        for(int i=0;i<n;i++)
            if(op[i]=='s')printf("%lld\n",sum[1][2]);
            else{
                int pos,_pos=std::lower_bound(wash,wash+len,raw[i])-wash+M;
                for(pos=_pos,cnt[pos]=(op[i]=='a'),pos/=2;pos;pos/=2)
                    cnt[pos]=cnt[pos<<1]+cnt[pos<<1|1];
                for(pos=_pos,sum[pos][0]=raw[i]*(op[i]=='a'),pos/=2;pos;pos/=2)
                    for(int i=0;i<5;i++)
                        sum[pos][i]=sum[pos<<1][i]+
                            sum[pos<<1|1][(i-cnt[pos<<1]+100000)%5];
            }
    }
    return 0;
}