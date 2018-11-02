#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<set>
const int maxn=5000005;
struct Node{
    int cnt;//1:未匹配串尾 0:无 -1:已匹配串尾
    Node*fail,*pre;
    Node*next[26];
}node[maxn],*rt;
int cnt;
Node*newnode(Node*f=0){
    node[cnt].pre=f;
    return node+cnt++;
}
void insert(char*s){
    Node*p=rt;
    for(char*i=s;*i;i++){
        int k=*i-'A';
        if(p->next[k]==NULL)
            p->next[k]=newnode(p);
        p=p->next[k];
    }p->cnt=1;
}
void inif(){
    std::queue<Node*>q;q.push(rt);
    while(q.size()){
        Node*u=q.front();q.pop();
        for(int i=0;i<26;i++){
            Node*&v=u->next[i];
            if(v)q.push(v);
            (v?v->fail:v)=(u==rt?rt:u->fail->next[i]);
        }
    }
}
typedef std::set<Node*>::iterator itor;
int query(char*s){
    Node*p=rt,*q;std::set<Node*>uset,vset;
    for(char*i=s;*i;i++)
        for(q=p=p->next[*i-'A'];q!=rt&&q->cnt==1;q=q->fail)
            uset.insert(q),q->cnt=-1;
    for(itor it=uset.begin();it!=uset.end();it++)
        for(p=*it;p!=rt;p=p->pre)
            for(q=(p==*it?p->fail:p);q!=rt;q=q->fail)
                if(q->cnt==-1)
                    vset.insert(q),q->cnt=0;
    return uset.size()-vset.size();
}
char str[maxn];
void getstr(){
    char x,c;int m,i=0;
    while((x=getchar())!='\n'&&~x){
        if(x=='['){
            scanf("%d%c%*c",&m,&c);
            while(m--)str[i++]=c;
        }else str[i++]=x;
    }str[i]=0;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d%*c",&n);
        cnt=0;rt=newnode();
        while(n--){
            getstr();
            insert(str);
        }inif();
        getstr();
        printf("%d\n",query(str));
        memset(node,0,cnt*sizeof(Node));
    }
    return 0;
}