//#include <queue>
//#define NodeNum 1
//#define EdgeNum 1
//int n;
//struct ACautomata
//{
//	int next[NodeNum][EdgeNum],fail[NodeNum],end[NodeNum];
//	int root,cnt;
//	int newNode()
//	{
//		for(int i=1;i<=n;i++) 
//			next[cnt][i]=-1;
//		end[cnt++]=0;
//		return cnt-1;
//	}
//	void init()
//	{
//		cnt=0;
//		root=newNode();
//	}
//	void insert(int a[],int len)
//	{
//		int now=root;
//		for(int i=0;i<len;i++)
//		{
//			if(next[now][a[i]]==-1)
//				next[now][a[i]]=newNode();
//			now=next[now][a[i]];
//		}
//		end[now]=1;
//	}
//	void build()
//	{
//		std::queue<int> q;
//		fail[root]=root;
//		for(int i=1;i<=n;i++)
//		{
//			if(next[root][i]==-1)
//				next[root][i]=root;
//			else
//			{
//				fail[next[root][i]]=root;
//				q.push(next[root][i]);
//			}
//		}
//		while(!q.empty())
//		{
//			int now=q.front();
//			q.pop();
//			end[now]|=end[fail[now]];
//			for(int i=1;i<=n;i++)
//			{
//				if(next[now][i]==-1)
//					next[now][i]=next[fail[now]][i];
//				else
//				{
//					fail[next[now][i]]=next[fail[now]][i];
//					q.push(next[now][i]);
//				}
//			}
//		}
//	}
//}ac;