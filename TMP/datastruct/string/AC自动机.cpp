////*********************\
//*1.勿忘inif()\
//*2.max 设置\
//*3.string.h和queue 要加上\
//*4.root=new node()\
//*/
//#include<stdio.h>
//#include<string.h>
//#include<queue>
//#define max 26
//#define Es(node,str_ptr) node->next[*str_ptr-'a']
//#define Ei(node,id) node->next[id]
//struct node
//{
//	node*next[max];
//	node*fail;
//	int count;
//	node(){fail=NULL,count=0,memset(next,NULL,sizeof next);}
//}*root;
//char str[1000005];
//void insert(char*str)
//{
//	node*p=root;
//	char*s=str;
//	while(*s)
//	{
//		if(Es(p,s)==NULL)
//			Es(p,s)=new node();
//		p=Es(p,s++);
//	}
//	p->count++;
//}
//void inif()
//{
//	std::queue<node*>q;
//	root->fail=NULL;
//	q.push(root);
//	while(q.size())
//	{
//		node*cur=q.front();q.pop();
//		node*p=NULL;
//		for(int i=0;i<max;i++)
//		{
//			if(Ei(cur,i))
//			{
//				q.push(Ei(cur,i));
//				if(cur==root)
//				{
//					Ei(cur,i)->fail=root;
//					continue;
//				}
//				p=cur->fail;
//				Ei(cur,i)->fail=root;
//				while(p)
//				{
//					if(Ei(p,i))
//					{
//						Ei(cur,i)->fail=Ei(p,i);
//						break;
//					}
//					p=p->fail;
//				}
//			}
//		}
//	}
//}
//int query(char*str)
//{
//	char*q=str;
//	int cnt=0;
//	node*p=root;
//	while(*q)
//	{
//		while(Es(p,q)==NULL&&p!=root)
//			p=p->fail;
//		p=Es(p,q);
//		if(p==NULL)
//			p=root;
//		node*t=p;
//		while(t!=root&&t->count!=-1)
//		{
//			cnt+=t->count;
//			t->count=-1;
//			t=t->fail;
//		}
//		q++;
//	}
//	return cnt;
//}