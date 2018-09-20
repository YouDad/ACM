#include<stdio.h>
#include<vector>
char s[105];
int main(){
#ifdef LOCAL_DEBUG
    freopen("E:/ACM/SRC/1.txt","r",stdin);
#endif
    int n;scanf("%d",&n);
    std::vector<int>va,vA,v1;
    for(int i=0;i<n;i++){
        scanf("%s",s);
        va.clear();vA.clear();v1.clear();
        for(int i=0;s[i];i++){
            if('0'<=s[i]&&s[i]<='9')
                v1.push_back(i);
            else if('a'<=s[i]&&s[i]<='z')
                va.push_back(i);
            else
                vA.push_back(i);
        }
        if(va.size()==0&&v1.size()==0){
            s[0]='0';s[1]='a';
        }else if(va.size()==0&&vA.size()==0){
            s[0]='A';s[1]='a';
        }else if(v1.size()==0&&vA.size()==0){
            s[0]='0';s[1]='A';
        }else if(v1.size()==0){
            if(va.size()>1)s[va[0]]='0';
            else s[vA[0]]='0';
        }else if(va.size()==0){
            if(v1.size()>1)s[v1[0]]='a';
            else s[vA[0]]='a';
        }else if(vA.size()==0){
            if(va.size()>1)s[va[0]]='A';
            else s[v1[0]]='A';
        }puts(s);
    }
    return 0;
}