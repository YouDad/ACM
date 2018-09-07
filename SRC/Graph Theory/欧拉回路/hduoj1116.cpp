#include<stdio.h>
#include<string.h>
const int maxn='z'+5;
int pre[maxn],idegree[maxn],odegree[maxn];
char s[1005];
int find(int x){return x==pre[x]?x:pre[x]=find(pre[x]);}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i='a';i<='z';i++){
            pre[i]=i;
            idegree[i]=0;
            odegree[i]=0;
        }
        for(int i=0;i<n;i++){
            scanf("%s",s);
            int len=strlen(s)-1;
            odegree[s[0]]++;
            idegree[s[len]]++;
            pre[find(s[0])]=pre[find(s[len])];
        }
        bool flag=false;
        int cnt=0;
        for(int i='a';i<='z';i++)
            cnt+=(pre[i]==i&&(idegree[i]+odegree[i]));
        if(cnt==1){
            cnt=0;
            for(int i='a';i<='z';i++){
                if(idegree[i]!=odegree[i]){
                    if(idegree[i]==odegree[i]+1||
                       idegree[i]==odegree[i]-1){
                        cnt++;
                    }else{
                        cnt=3;
                        break;
                    }
                }
            }
            flag=cnt==0||cnt==2;
        }
        if(flag)
            puts("Ordering is possible.");
        else
            puts("The door cannot be opened.");
    }
    return 0;
}