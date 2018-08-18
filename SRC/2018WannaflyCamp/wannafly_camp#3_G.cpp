#include<stdio.h>
// #include<string.h>
// #include<set>
// int sg[1000];
// void solve(int a,int b){
//     memset(sg,0,sizeof sg);
//     for(int i=b+1;i<1000;i++){
//         std::set<int>s;
//         for(int j=a;j<=b;j++)
//          if(!(a<=i-j&&i-j<=b))
//              s.insert(sg[i-j]);
//         while(s.count(sg[i]))sg[i]++;
//     }
//     for(int i=0;i<1000;i++)
//         printf("(%d,%d)",i,sg[i]);
// }
int ssg1(int x,int a,int b){
    if(a<=x&&x<=b)return 0;
    return x%(b+1);
}
int ssga(int x,int a,int b){
    if(x<=b)return 0;
    int s=(x-b)%(a+b)/a;
    return s>1?s:1-s;
}
int main(){
    // for(int i=0;i<1000;i++)
    //     printf("(%d,%d)",i,ssg1(i,1,20));
    // for(int i=0;i<1000;i++)
    //     printf("(%d,%d)",i,ssga(i,3,20));
    // solve(1,20);
    int t;scanf("%d",&t);
    while(t--){
        int n,a,b,s,nim=0,win=0;
        scanf("%d%d%d",&n,&a,&b);
        if(a>1)
            for(int i=0,x;i<n;i++)
                scanf("%d",&x),
                nim^=ssga(x,a,b),
                win+=(a<=x&&x<=b);
        else
            for(int i=0,x;i<n;i++)
                scanf("%d",&x),
                nim^=ssg1(x,a,b),
                win+=(a<=x&&x<=b);
        puts(win?"Yes":(nim?"Yes":"No"));
    }
    return 0;
}