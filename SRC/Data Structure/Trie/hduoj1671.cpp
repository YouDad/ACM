#include<stdio.h>
#include<string.h>
const int maxn=1e5+5;
struct Node{
    bool terminal;
    Node*next[10];
}node[maxn],head;
int cnt;bool flag;
Node*newnode(){return node+cnt++;}
void insert(char*s){
    Node*p=&head;bool newed=false;
    for(char*i=s;*i;i++){
        if(p->terminal)flag=false;
        if(p->next[*i-'0']==NULL)
            p->next[*i-'0']=newnode(),newed=true;
        p=p->next[*i-'0'];
    }p->terminal=true;
    if(!newed)flag=false;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    char str[15];
    int T;scanf("%d%*c",&T);
    while(T--){
        int n;scanf("%d%*c",&n);
        flag=true;cnt=0;
        memset(head.next,0,sizeof head.next);
        for(int i=0;i<n;i++){
            gets(str);
            if(flag)
                insert(str);
        }
        puts(flag?"YES":"NO");
        if(T)memset(node,0,cnt*(sizeof Node));
    }
    return 0;
}