// https://nanti.jisuanke.com/t/31458
#include<stdio.h>
#include<map>
#define newmap m[i&1]
#define lastmap m[1-i%2]
struct Node{
    int x,y;
    Node(int xx=0,int yy=0){
        xx=x;
        yy=y;
    }
    bool operator<(const Node&other)const{
        return x==other.x?y<other.y:x<other.x;
    }
    bool operator>(const Node&other)const{
        return !(*this<other||*this==other);
    }
    bool operator==(const Node&other)const{
        return x==other.x&&y==other.y;
    }
}node;
#define foreach(it,obj) for(auto it=obj->begin();it!=obj->end();)
std::map<Node,int>*m[2];
int main(){
#ifdef LOCAL_DEBUG
	freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        m[1]=new std::map<Node,int>();
        int n,max=0;scanf("%d",&n);
        for(int i=0;i<n;i++){
            newmap=new std::map<Node,int>();
            int k;scanf("%d",&k);
            while(k--){
                scanf("%d%d",&node.x,&node.y);
                newmap->operator[](node)=1;
            }
			auto it=newmap->begin(),jt=lastmap->begin();
			while(it!=newmap->end()&&jt!=lastmap->end()){
				if(jt->first<it->first)
                    jt++;
				else if(jt->first>it->first)
					it++;
				else{
                    it->second+=jt->second;
                    if(it->second>max)
                        max=it->second;
                    it++,jt++;
                }
			}
        }
        if(max==1)
            puts("0");
        else
            printf("%d\n",max);
    }
    return 0;
}