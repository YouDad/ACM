#include<stdio.h>
#include<string.h>
#include<queue>
struct Node{
    int cnt;
    Node*fail;
    Node*next[26];
}node[250005],*rt;
int cnt;
Node*newnode(){return node+cnt++;}
void insert(char*s){
    Node*p=rt;
    for(char*i=s;*i;i++){
        int k=*i-'A';
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
    Node*p=rt,*q;int ret=0;char*i;
    for(i=s;*i;i++){//forward match
        q=p=p->next[*i-'A'];
        while(q!=rt){
            if(q->cnt){
                ret+=q->cnt;
                q->cnt=0;
            }else break;
            q=q->fail;
        }
    }i--;
    for(p=rt;i!=s-1;i--){//backward match
        p=p->next[*i-'A'];
        Node*q=p;
        while(q!=rt){
            if(q->cnt){
                ret+=q->cnt;
                q->cnt=0;
            }else break;
            q=q->fail;
        }
    }return ret;
}
char str[5100005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        cnt=0;rt=newnode();
        for(int i=0;i<n;i++)
            scanf("%s%*c",str),insert(str);
        int x,i=0;char c;
        while((c=getchar())!='\n'&&~c){
            if(c=='['){
                scanf("%d%c%*c",&x,&c);
                while(x--)str[i++]=c;
            }else str[i++]=c;
        }str[i]=0;inif();
        printf("%d\n",query(str));
        if(T)memset(node,0,cnt*sizeof(Node));
    }
    return 0;
}