#include<stdio.h>
#include<string.h>
class vec{public:int x,y;
    vec(int xx=0,int yy=0){x=xx;y=yy;}
    int operator^(vec& other){
        return x*other.y-y*other.x;
    }
};
class point:public vec{public:
    vec operator-(point& other){
        return vec(x-other.x,y-other.y);
    }
}p;
class Line{public:point s,e;
    void set(int xs,int ys,int xe,int ye){
        s.x=xs;s.y=ys;e.x=xe;e.y=ye;
    }
}line[5005];
bool check(Line l){//point is right of Line?
    vec a=l.e-l.s,b=p-l.s;
    return (a^b)<0;
}
int ans[5005];
int main(){
    int n,m,x,y,yh,yl,u,d;
    while(1!=scanf("%d%d%d%d%*d%d",&n,&m,&x,&yh,&yl)){
static bool first=true;if(first)first=false;else putchar('\n');
        line[0].set(x,yl,x,yh);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&u,&d),
            line[i].set(d,yl,u,yh);
        memset(ans,0,sizeof ans);
        while(m--){
            scanf("%d%d",&x,&y);p.x=x;p.y=y;
            int L=0,R=n;
            while(R-L>1)
                (check(line[L+R>>1])?L:R)=L+R>>1;
            if(check(line[R]))L=R;
            ans[L]++;
        }
        for(int i=0;i<=n;i++)
            printf("%d: %d\n",i,ans[i]);
    }
    return 0;
}