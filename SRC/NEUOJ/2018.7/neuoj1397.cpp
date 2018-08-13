#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct BigInteger{
    static const int BASE=100000000;
    static const int WIDTH=8;
    vector<int>s;
    BigInteger(long long num=0){*this=num;}
    BigInteger&operator =(long long num){
        s.clear();
        do{
            s.push_back(num%BASE);
            num/=BASE;
        }while(num>0);
        return *this;
    }
    BigInteger&operator =(const string& str){
        s.clear();
        int x,len=(str.length()-1)/WIDTH+1;
        for(int i=0;i<len;i++){
            int end=str.length()-i*WIDTH;
            int start=max(0,end-WIDTH);
            sscanf(str.substr(start,end-start).c_str(),"%d",&x);
            s.push_back(x);
        }
        return *this;
    }
    friend ostream&operator<<(ostream&out,const BigInteger&x){
		int i=x.s.size()-1;
		while(x.s[i]==0)i--;
		out<<x.s[i--];
        for(;i>=0;i--){
            char buf[20];sprintf(buf,"%08d",x.s[i]);
            out<<buf;
        }
        return out;
    }
    friend istream&operator>>(istream&in,BigInteger&x){
        string s;
        if(!(in>>s))return in;
        x=s;
        return in;
    }
    BigInteger operator+(const BigInteger&b)const{
        BigInteger c;
        c.s.clear();
        for(int i=0,g=0;;i++){
            if(g==0&&i>=s.size()&&i>=b.s.size())break;
            int x=g;
            if(i<s.size())x+=s[i];
            if(i<b.s.size())x+=b.s[i];
            c.s.push_back(x%BASE);
            g=x/BASE;
        }
        return c;
    }
	BigInteger operator*(const BigInteger&b)const{
		BigInteger a,c,d=0;
		if(b>*this)
			a=b,c=*this;
		else
			a=*this,c=b;
		while(c>0)
		{
			if(c.s[0]%2==1)d=d+a;
			a=a+a;
			for(int i=c.s.size()-1;i>=0;i--)
			{
				if(i>0&&c.s[i]%2==1)
					c.s[i-1]+=100000000;
				c.s[i]/=2;
			}
		}
		return d;
	}
    bool operator<(const BigInteger&b)const{
		int i=s.size()-1,j=b.s.size()-1;
		while(i&&s[i]==0)i--;
		while(j&&b.s[j]==0)j--;
        if(i!=j)return i<j;
        for(;i>=0;i--)
            if(s[i]!=b.s[i])return s[i]<b.s[i];
        return false;
    }
    bool operator>(const BigInteger&b)const{return b<*this;}
    bool operator<=(const BigInteger&b)const{return !(b<*this);}
    bool operator>=(const BigInteger&b)const{return !(*this<b);}
    bool operator!=(const BigInteger&b)const{return b<*this||*this<b;}
    bool operator==(const BigInteger&b)const{return !(b!=*this);}
}ans[105]={};
void init(){
    ans[1]=1;
    ans[2]=5;
    for(int i=3;i<=100;i++)
        ans[i]=ans[i-1]+(ans[i-2]+1)*i*i;
}
int main(){
    init();
    int n;
    while(cin>>n)
        cout<<ans[n]<<endl;
    return 0;
}