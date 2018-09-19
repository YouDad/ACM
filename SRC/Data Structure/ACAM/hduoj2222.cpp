#include<stdio.h>
#include<string.h>
#include<queue>
struct Node{
    int cnt;
    Node*fail;
    Node*next[26];
}node[500005],*rt;
int cnt;
Node*newnode(){return node+cnt++;}
void insert(char*s){
    Node*p=rt;
    for(char*i=s;*i;i++){
        int k=*i-'a';
        if(p->next[k]==NULL)
            p->next[k]=newnode();
        p=p->next[k];
    }p->cnt++;
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
int query(char*s){
    Node*p=rt;int ret=0;
    for(char*i=s;*i;i++){
        p=p->next[*i-'a'];
        Node*q=p;
        while(q!=rt){
            if(~q->cnt)
                ret+=q->cnt,
                q->cnt=-1;
            else break;
            q=q->fail;
        }
    }
    return ret;
}
char str[1000005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        cnt=0;rt=newnode();
        for(int i=0;i<n;i++){
            scanf("%s",str);
            insert(str);
        }inif();
        scanf("%s",str);
        printf("%d\n",query(str));
        memset(node,0,cnt*sizeof(Node));
    }
    return 0;
}