#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
struct Node{
    int val;//is terminal
    Node*next[26];
}node[maxn],*head;
int cnt;string word[50005];
Node*newnode(){return node+cnt++;}
void insert(const char*s){
    Node*p=head;
    for(const char*i=s;*i;i++){
        if(p->next[*i-'a']==NULL)
            p->next[*i-'a']=newnode();
        p=p->next[*i-'a'];
    }p->val=true;
}
bool find(const char*s){
    Node*p=head;
    for(const char*i=s;*i;i++){
        if(p->next[*i-'a'])
            p=p->next[*i-'a'];
        else return false;
    }return p->val;
}
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int c=0;head=newnode();
    while(cin>>word[++c])
        insert(word[c].c_str());
    for(int i=1;i<=c;i++){
        string str="";
        for(int j=1;word[i][j];j++){
            str+=word[i][j-1];
            if(find(str.c_str())&&find(word[i].c_str()+j)){
                cout<<word[i]<<endl;
                break;
            }
        }
    }
    return 0;
}