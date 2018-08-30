#include<stdio.h>
#include<algorithm>
#include<map>
typedef std::map<int,int>::iterator itor;
class vec{public:int x,y;
    vec(int xx=0,int yy=0){x=xx;y=yy;}
    int cross(vec& other){
        return x*other.y-y*other.x;
    }
};
class point:public vec{public:
    vec operator-(point& other){
        return vec(x-other.x,y-other.y);
    }
}p;
struct Line{point s,e;
    void set(int sx,int sy,int ex,int ey){
        s.x=sx;s.y=sy;e.x=ex;e.y=ey;
    }
    bool operator<(Line const&other)const{
        return e.x<other.e.x;
    }
}line[1005];
bool check(Line&l){//right?
    vec a=l.e-l.s,b=p-l.s;
    return a.cross(b)<0;
}
int main(){
    for(int n;scanf("%d",&n)&&n;){
        int m,x,yh,yl,xl,xh;
        scanf("%d%d%d%*d%d",&m,&x,&yh,&yl);
        line[0].set(x,yl,x,yh);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&xh,&xl),
            line[i].set(xl,yl,xh,yh);
        std::map<int,int>map;
        std::sort(line,line+1+n);
        while(m--){
            scanf("%d%d",&p.x,&p.y);
            int L=0,R=n;
            while(R-L>1)
                (check(line[L+R>>1])?L:R)=L+R>>1;
            if(check(line[R]))L=R;
            map[L]++;
        }
        puts("Box");std::map<int,int>ans;
        for(itor it=map.begin();it!=map.end();it++)
            ans[it->second]++;
        for(itor it=ans.begin();it!=ans.end();it++)
            printf("%d: %d\n",it->first,it->second);
    }
    return 0;
}