//用build之前应先让node的l&r=0,node[1~n].v赋上初值
//返回值是根节点编号
struct Node{int v,l,r;}node[maxn];
int build(int n){
    int rt=0;std::stack<int>s;
    for(int i=1,pre=0;i<=n;i++,pre=0){
        while(s.size()&&node[s.top()].v<node[i].v)
            pre=s.top(),s.pop();
        if(s.size())node[s.top()].r=i;else rt=i;
        node[i].l=pre;s.push(i);
    }return rt;
}