#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
map<string,int>m;
int ideg[1005];
int main(){
    for(int n;cin>>n&&n;){
        m.clear();int cnt=0;
        memset(ideg,0,sizeof ideg);
        string u,v;
        for(int i=0;i<n;i++){
            cin>>u>>v;
            if(!m.count(u))
                m[u]=cnt++;
            if(!m.count(v))
                m[v]=cnt++;
            ideg[m[v]]++;
        }
        int single=0;
        for(int i=0;i<cnt;i++)
            single+=ideg[i]==0;
        puts(single-1?"No":"Yes");
    }
    return 0;
}