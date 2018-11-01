#include<stdio.h>
#include<string.h>
const int maxn=1e6+5;
struct Node{
    int val;//count of prefix
    Node*next[26];
}node[maxn],*head;
int cnt;
Node*newnode(){
    return node+cnt++;
}
void insert(char*s){
    Node*p=head;
    for(char*i=s;*i;i++){
        p->val++;
        if(p->next[*i-'a']==NULL)
            p->next[*i-'a']=newnode();
        p=p->next[*i-'a'];
    }p->val++;
}
int match(char*s){
    Node*p=head;
    for(char*i=s;*i;i++){
        if(p->next[*i-'a'])
            p=p->next[*i-'a'];
        else return 0;
    }return p->val;
}
char str[1005];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    head=newnode();
    while(gets(str))
        if(str[0])
            insert(str);
        else break;
    while(gets(str))
        if(str[0])
            printf("%d\n",match(str));
        else break;
    return 0;
}