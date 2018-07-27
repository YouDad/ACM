#include<stdio.h>
#include<string.h>
#define Es(node,str_ptr) node->next[*str_ptr-'a']
#define Ei(node,id) node->next[id]
#define max 26
#define maxn 21
struct node
{
    node* next[max];
    int iptr;
    node(int num=-1)
    {
        memset(next,NULL,sizeof(next));
        iptr=num;
    }
};
node* const root=new node();
char map[1005][21];
void insert(int iptr)
{
    char*p=map[iptr];
    node*q=root;
    while(*p)
    {
        char t=*(p+1);
        *(p+1)=0;
        if(Es(q,p)==NULL)
            Es(q,p)=new node(iptr);
        else
            Es(q,p)->iptr=-2;
        q=Es(q,p);
        *(++p)=t;
    }
}
void print(int iptr)
{
    char*p=map[iptr];
    node*q=root;
    while(q->iptr<=-1&&*p)
        putchar(*p),
        q=Es(q,p++);
}