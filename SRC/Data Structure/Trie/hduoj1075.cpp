#include<stdio.h>
#include<string.h>
const int maxn=1e6+5;
struct Node{
    int val;//index of word
    Node*next[26];
}node[maxn],*head;
int cnt;
char word[maxn][11];
char str[maxn],buf[maxn];
Node*newnode(){
    node[cnt].val=-1;
    memset(node[cnt].next,0,sizeof node[cnt].next);
    return node+cnt++;
}
void insert(char*s,int idx){
    Node*p=head;int len=strlen(s);
    for(int i=0;i<len;i++){
        int num=s[i]-'a';
        if(p->next[num]==NULL)
            p->next[num]=newnode();
        p=p->next[num];
    }p->val=idx;
}
int search(char*s){
    Node*p=head;char*x=s;
    while(*x){
        int num=*x++-'a';
        if(p->next[num])
            p=p->next[num];
        else
            return -1;
    }return p->val;
}
void solve(char*s){
    for(int i=0;s[i];){
        if(s[i]<'a'||'z'<s[i]){
            putchar(s[i++]);
            continue;
        }
        int j=i;
        while('a'<=s[i]&&s[i]<='z')
            buf[i-j]=s[i++];buf[i-j]=0;
        int ret=search(buf);
        printf("%s",~ret?word[ret]:buf);
    }putchar('\n');
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    head=newnode();
    int wcnt=0;
    scanf("%*s");
    while(scanf("%s",word[wcnt])){
        if(strcmp(word[wcnt],"END"))
            scanf("%s",str),insert(str,wcnt++);
        else break;
    }
    scanf("%*s%*c");
    while(gets(str)){
        if(strcmp(str,"END"))
            solve(str);
        else break;
    }
    return 0;
}