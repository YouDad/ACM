#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
const int maxn=5000005;
int next[maxn],tlen;char*t;
void getnext(char*s,int len){
    t=s;tlen=len;
    for(int i=1;i<len;i++){
        int j=next[i];
        while(j&&s[i]!=s[j])j=next[j];
        next[i+1]=s[i]==s[j]?j+1:0;
    }
}
bool kmatch(char*s,int slen){
    if(slen<tlen||s==t)return false;
    for(int i=0,j=0;i<slen;i++){
        while(j&&s[i]!=t[j])j=next[j];
        if(s[i]==t[j])j++;
        if(j==tlen)return true;
    }return false;
}
struct Node{
    int cnt;char ch;
    Node*fail,*pre;
    Node*next[26];
}node[maxn],*rt;
int cnt;
Node*newnode(Node*f,char c){
    node[cnt].pre=f;
    node[cnt].ch=c;
    return node+cnt++;
}
void insert(char*s){
    Node*p=rt;
    for(char*i=s;*i;i++){
        int k=*i-'A';
        if(!p->next[k])
            p->next[k]=newnode(p,*i);
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
            (v?v->fail:v)=(u==rt?
                rt:u->fail->next[i]);
        }
    }
}
int query(char*s){
    Node*p=rt,*q;std::vector<Node*>v;
    for(char*i=s;*i;i++){
        q=p=p->next[*i-'A'];
        while(q!=rt){
            if(q->cnt<0)break;
            else{
                if(q->cnt)
                    v.push_back(q);
                q->cnt=-1;
            }
            q=q->fail;
        }
    }
    std::vector<int>iv(v.size()+1);iv[0]=-1;
    for(int i=0;i<v.size();i++){
        iv[i+1]=++iv[i];
        for(p=v[i];p!=rt;p=p->pre)
            s[iv[i+1]++]=p->ch;
        s[iv[i+1]]=0;
    }iv[v.size()]++;
    int ret=iv.size()-1;
    for(int i=0;i<v.size();i++){
        getnext(s+iv[i],iv[i+1]-iv[i]-1);
        for(int j=0;j<v.size();j++){
            if(kmatch(s+iv[j],iv[j+1]-iv[j]-1)){
                ret--;
                break;
            }
        }
    }
    return ret;
}
char str[maxn];
void getstr(){
    char x,c;int m,i=0;
    while((x=getchar())!='\n'&&~x){
        if(x=='['){
            scanf("%d%c%*c",&m,&c);
            while(m--)str[i++]=c;
        }else str[i++]=x;
    }
    str[i]=0;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d%*c",&n);
        cnt=0;rt=newnode(0,0);
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