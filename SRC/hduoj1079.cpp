#include<string.h>
#include<stdio.h>
#include<set>
class date{
public:
    int y,m,d;
    date(int year,int month,int day){
        y=year;m=month;d=day;
    }
    date(int i){d=i%31+1;m=i/31%12+1;y=i/31/12+1900;}
    date(){y=m=d=0;}
    operator int(){
        return d+m*31+y*372-1900*372-31-1;
    }
    inline bool can_sub_month(){
        if(m==3)
            return d<=28+(y!=1900&&y%4==0);
        else if(m==5||m==7||m==10||m==12)
            return d!=31;
        return true;
    }
    inline void sub_month(){
        y-=m==1;
        m=--m?m:12;
    }
    inline bool can_next_month(){
        if(m==1)
            return d<=28+(y!=1900&&y%4==0);
        else if(m==3||m==5||m==8||m==10)
            return d!=31;
        return true;
    }
    inline void next_month(){
        y+=m==12;
        m=(m+1)%13+(m==12);
    }
    date operator--(int){
        date ret=*this;
        if(d!=1)d--;
        else{
            sub_month();
            if(m==2)
                if(y!=1900&&y%4==0)
                    d=29;
                else
                    d=28;
            else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
                d=31;
            else
                d=30;
        }
        return ret;
    }
    date operator ++(int){
        date ret=*this;
        int leap_month=(m==2)*2;
        int leap_year=m==2&&y!=1900&&y%4==0;
        int big_month=m==1||m==3||m==5||m==7||m==8||m==10||m==12;
        int delta=big_month-leap_month+leap_year;
        int final_day=d==30+delta;
        if(final_day){
            y+=m==12;
            m=(m+1)%13+(m==12);
        }
        d=(d+1)%(31+delta)+final_day;
        return ret;
    }
    date operator+(int){
        date ret=*this;
        ret++;return ret;
    }
    date operator-(int){
        date ret=*this;
        ret--;return ret;
    }
    date operator/(int){
        date ret=*this;
        if(ret.can_sub_month())
            ret.sub_month();
        return ret;
    }
    date operator*(int){
        date ret=*this;
        if(ret.can_next_month())
            ret.next_month();
        return ret;
    }
#define gen_relation(sign) bool operator sign(int x){return int(*this)sign x;}
    gen_relation(<)
    gen_relation(>)
    gen_relation(==)
    gen_relation(>=)
    gen_relation(!=)
    gen_relation(<=)
};
int sg[50000];
void solve(){
    memset(sg,-1,sizeof sg);
	date i(2001,11,4);
	sg[i--]=0;
    for(;i>=date(2001,10,5);i--){
        std::set<int>s;
		s.insert(sg[i+1]);
        sg[i]=0;while(s.count(sg[i]))sg[i]++;
    }
	for(;i>=0;i--){
        std::set<int>s;
        if(i.can_next_month())
			s.insert(sg[i*1]);
		s.insert(sg[i+1]);
        sg[i]=0;while(s.count(sg[i]))sg[i]++;
    }
}
int main(){
    solve();
    int t,y,m,d;
    scanf("%d",&t);
    while(t--)
        scanf("%d%d%d",&y,&m,&d),
        puts(sg[date(y,m,d)]?"YES":"NO");
    return 0;
}