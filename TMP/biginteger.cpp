//#include<stdio.h>
//#include<memory.h>
//#define clear(Array) memset(Array,0,sizeof(Array));
//#define private private:
//#define public public:
//#define protected protected:
////重要声明:G++编译过不了,C++可以过
//class Integer
//{
//	public int static const bit=2;
//	private long long ptr[bit+1];
//	private long long static const up=1000000000;
//	public Integer()
//	{
//		clear(ptr);
//	}
//	public Integer(int small)
//	{
//		clear(ptr);
//		int i=bit;
//		while(small)
//		{
//			ptr[i--]=small%up;
//			small/=up;
//		}
//	}
//	public Integer(long long small)
//	{
//		clear(ptr);
//		int i=bit;
//		while(small)
//		{
//			ptr[i--]=small%up;
//			small/=up;
//		}
//	}
//	public Integer(char* num)
//	{
//		int size=180;
//		char str[180+1];
//		clear(str);
//		clear(ptr);
//		while(*num)
//		{
//			str[size--]=*num++;
//		}
//		int len=180-size;
//		int need=len/9;
//		for(int j=0;j<=need;j++)
//			for(int i=(need==j?9*(j+1)-len:0);i<9;i++)
//				ptr[bit-j]=ptr[bit-j]*10+str[size+9*(j+1)-i]-'0';
//	}
//	public Integer(Integer& copy)
//	{
//		memcpy(ptr,copy.ptr,sizeof(copy.ptr));
//	}
//	public Integer(long long arr[bit+1])
//	{
//		memcpy(ptr,arr,8*bit+8);
//	}
//	public Integer&operator++ ()
//	{
//		return (*this+=Integer(1));
//	}
//	public Integer operator++ (int)
//	{
//		Integer old(*this);
//		*this+=Integer(1);
//		return old;
//	}
//	public Integer&operator-- ()
//	{
//		return (*this-=Integer(1));
//	}
//	public Integer operator-- (int)
//	{
//		Integer old(*this);
//		*this-=Integer(1);
//		return old;
//	}
//	public Integer&operator=  (Integer& other)
//	{
//		memcpy(this->ptr,other.ptr,sizeof(other.ptr));
//		return *this;
//	}
//	public Integer&operator=  (int other)
//	{
//		*this=Integer(other);
//		return *this;
//	}
//	public Integer&operator=  (long long other)
//	{
//		*this=Integer(other);
//		return *this;
//	}
//	public Integer operator+  (Integer& other)
//	{
//		long long jw=0;
//		long long res[bit+1];
//		clear(res);
//		for(int i=bit;i>=1;i--)
//		{
//			res[i]=(ptr[i]+other.ptr[i]+jw)%up;
//			jw=(ptr[i]+other.ptr[i]+jw)/up;
//		}
//		return Integer(res);
//	}
//	public Integer&operator+= (Integer& other)
//	{
//		return (*this=*this+other);
//	}
//	public Integer operator-  (Integer& other)
//	{
//		long long cur=0;
//		long long res[bit+1];
//		clear(res);
//		for(int i=bit;i>=1;i--)
//		{
//			if(ptr[i]-cur>=other.ptr[i])
//			{
//				res[i]=ptr[i]-cur-other.ptr[i];
//				cur=0;
//			}
//			else
//			{
//				res[i]=ptr[i]+up-other.ptr[i]-cur;
//				cur=1;
//			}
//		}
//		return Integer(res);
//	}
//	public Integer operator-  ()
//	{
//		return (Integer()-*this);
//	}
//	public Integer&operator-= (Integer& other)
//	{
//		return (*this=*this-other);
//	}
//	public Integer operator*  (Integer& other)
//	{
//		if(*this<other)
//			return other*(*this);
//		Integer base(*this);
//		Integer index(other);
//		Integer ret;
//		while(index!=0)
//		{
//			if((index.ptr[bit]&1)==1)
//				ret+=base;
//			base+=base;
//			index>>=1;
//		}
//		return ret;
//	}
//	public Integer operator*  (int other1)
//	{
//		Integer other(other1);
//		if(*this<other)
//			return other*(*this);
//		Integer base(*this);
//		Integer index(other);
//		Integer ret;
//		while(index!=0)
//		{
//			if((index.ptr[bit]&1)==1)
//				ret+=base;
//			base+=base;
//			index>>=1;
//		}
//		return ret;
//	}
//	public Integer operator*= (Integer& other)
//	{
//		return (*this=*this*other);
//	}
//	public Integer operator/  (int other)
//	{
//		Integer ret(*this);
//		int i=1;
//		while(!ret.ptr[i]&&i<=bit)
//				i++;
//		while(i<bit)
//		{
//			ret.ptr[i+1]+=ret.ptr[i]%other*up;
//			ret.ptr[i++]/=other;
//		}
//		ret.ptr[i]/=other;
//		return ret;
//	}
//	public Integer operator/= (int other)
//	{
//		return (*this=*this/other);
//	}
//	public Integer operator/  (Integer& other/*not complete*/)
//	{
//
//		return Integer();
//	}
//	public Integer operator/= (Integer& other)
//	{
//		return (*this=*this/other);
//	}
//	public Integer operator^  (Integer& other)
//	{
//		if(*this<other)
//			return other^(*this);
//		Integer base(*this);
//		Integer index(other);
//		Integer ret(1);
//		while(index!=0)
//		{
//			if((index.ptr[bit]&1)==1)
//				ret*=base;
//			base*=base;
//			index>>=1;
//		}
//		return ret;
//	}
//	public Integer operator%  (Integer& other)
//	{
//		return (*this-*this/other*other);
//	}
//	public Integer operator%  (int other)
//	{
//		return (*this-*this/other*other);
//	}
//	public Integer operator>> (Integer& other)
//	{
//		for(Integer i=0;i<other;i++)
//		{
//			for(int j=0;j<=bit;j++)
//				if(ptr[j]==0)
//					continue;
//				else if(ptr[j]!=0&&j!=bit)
//					ptr[j+1]+=up*(ptr[j]%2),
//					ptr[j]/=2;
//				else if(j==bit&&ptr[j]!=0)
//					ptr[j]/=2;
//		}
//		return *this;
//	}
//	public Integer&operator>>=(Integer& other)
//	{
//		return (*this=*this>>other);
//	}
//	public Integer&operator>>=(int other)
//	{
//		return (*this=*this>>Integer(other));
//	}
//	public Integer operator<< (Integer& other)
//	{
//		for(Integer i=0;i<other;i++)
//			*this+=*this;
//		return *this;
//	}
//	public Integer&operator<<=(Integer& other)
//	{
//		return (*this=*this<<other);
//	}
//	public Integer&operator<<=(int other)
//	{
//		return (*this=*this<<Integer(other));
//	}
//	public bool	  operator>  (Integer& other)
//	{
//		for(int i=0;i<=bit;i++)
//			if(ptr[i]>other.ptr[i])
//				return true;
//			else if(ptr[i]<other.ptr[i])
//				return false;
//		return false;
//	}
//	public bool	  operator<  (Integer& other)
//	{
//		return !(*this>other||*this==other);
//	}
//	public bool	  operator== (Integer& other)
//	{
//		for(int i=bit;i>=0;i--)
//			if(ptr[i]!=other.ptr[i])
//				return false;
//		return true;
//	}
//	public bool	  operator== (int other)
//	{
//		for(int i=0;i<bit;i++)
//			if(ptr[i])
//				return false;
//		return ptr[bit]==other;
//	}
//	public bool	  operator== (long long other)
//	{
//		for(int i=0;i<bit;i++)
//			if(ptr[i])
//				return false;
//		return ptr[bit]==other;
//	}
//	public bool	  operator!= (Integer& other)
//	{
//		return !(*this==other);
//	}
//	public bool	  operator!= (int other)
//	{
//		return *this!=Integer(other);
//	}
//	public void show(char const * p=NULL)
//	{
//		int i=1;
//		while(!ptr[i]&&i<=bit)
//				i++;
//		printf("%lld",ptr[i++]);
//		while(i<=bit)
//			printf("%09lld",ptr[i++]);
//		printf("%s",p);
//	}
//};