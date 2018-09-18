#include<stdio.h>
#include<string.h>
const int maxn=1e6+5;
struct TrieNode{
    int cnt;
    TrieNode*next[26];
}node[maxn],head;
int cnt;
char str[1005];
TrieNode*newnode(){
    return node+cnt++;
}
void insert(char*s){
    TrieNode*p=&head;
    for(char*i=s;*i;i++){
        p->cnt++;
        if(p->next[*i-'a']==NULL)
            p->next[*i-'a']=newnode();
        p=p->next[*i-'a'];
    }p->cnt++;
}
int match(char*s){
    TrieNode*p=&head;
    for(char*i=s;*i;i++){
        if(p->next[*i-'a'])
            p=p->next[*i-'a'];
        else return 0;
    }return p->cnt;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
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