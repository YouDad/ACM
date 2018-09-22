#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<set>
using namespace std;
set<string>s[10],tmp;
set<string>*p;
string str;
void dfs(string pre,int l,int r,int n){
    if(!n){
        p->insert(pre);
        return;
    }for(int i=l;i<r-n+1;i++)
        dfs(pre+str[i],i+1,r,n-1);
}
#define inter(a,b) set_intersection(a.begin(),a.end(),\
b.begin(),b.end(),inserter(tmp,tmp.begin())),a.swap(tmp),tmp.clear()
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;
    while(cin>>n){
        for(int ii=0;ii<n;ii++){
            p=s+ii;p->clear();
            cin>>str;str+=str;
            int len=str.length()/2;
            for(int i=0;i<len;i++)
                for(int j=1;j<=len;j++)
                    dfs("",i,i+len,j);
        }
        for(int i=1;i<n;i++)inter(s[0],s[i]);
        string maxstr="0";int maxlen=0;
        for(auto it=s[0].begin();it!=s[0].end();it++)
            if(it->length()>maxlen)
                maxlen=it->length(),maxstr=*it;
        cout<<maxstr<<endl;
    }
    return 0;
}