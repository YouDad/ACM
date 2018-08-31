#include<stdio.h>
#include<string.h>
#include<set>
#include<map>
const int INF=0x3F3F3F3F,INSERT=1,DELETE=0;
std::set<int>s[50005];std::map<int,int>flen;
int M,N,x,w,mcnt[1<<17],mlen[50005],fpos[1<<18];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void Fupdate(int pos,int len,int mode){
    if(len<=0)return;flen[pos]=len;
    if(mode)s[len].insert(pos);else s[len].erase(pos);
    fpos[len+N]=s[len].empty()?INF:*s[len].begin();
    for(len=len+N>>1;len;len/=2)
        fpos[len]=min(fpos[len*2],fpos[len*2+1]);
}
int Fquery(int l,int r){
    for(x=INF,l+=N-1,r+=N+1;l^r^1;l/=2,r/=2){
        if(~l&1)x=min(x,fpos[l^1]);
        if( r&1)x=min(x,fpos[r^1]);
    }return x;
}
void Mupdate(int pos,int len,int mode){
    mlen[pos]=len*mode;pos++;mcnt[pos+=M]=mode;
    for(pos/=2;pos;pos/=2)mcnt[pos]=mcnt[pos*2]+mcnt[pos*2+1];
}
int Mquery(int rank){
    for(x=1;x<M;)
    if(rank<=mcnt[x*2])x=x*2;
    else rank-=mcnt[x*2],x=x*2+1;
    return x-M-1;
}
/*nc*/inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
/*cini*/int ch,res;
int cini(){
    while((ch=nc())<'0'||ch>'9');res=ch-'0';
    while((ch=nc())>='0'&&ch<='9')res=res*10+ch-'0';
    return res;
}
int main(){
    int T=cini();
    for(int kase=1;kase<=T;kase++){
        printf("Case #%d:\n",kase);
        int n=cini(),q=cini();
        M=1;while(M<n+4)M*=2;
        N=1;while(N<n+2)N*=2;
        for(int i=0;i<50005;i++)
            if(!s[i].empty())s[i].clear();
        memset(fpos,0x3F,sizeof fpos);
        memset(mcnt,0x00,sizeof mcnt);
        memset(mlen,0x00,sizeof mlen);
        flen.clear();flen[INF]=INF;
        Fupdate(1-0,n,INSERT);
        Mupdate(1-1,1,INSERT);
        Mupdate(n+1,1,INSERT);
        while(q--){
            if(nc()=='A'){
                int PrevFree,LastFree,ans;
                int m=cini(),l=cini(),r=cini();
                if(m>n){puts("-1");continue;}
                PrevFree=Mquery(2);
                LastFree=Mquery(mcnt[1]-1);
                LastFree=n+1-LastFree-mlen[LastFree];
                int pos=Fquery(m,min(n,m+l+r)),len=flen[pos];
                if(PrevFree>m&&mcnt[1]==2){
                    Fupdate(1,PrevFree-1,DELETE);
                    Mupdate(ans=1,m,INSERT);
                    Fupdate(m+1,n-m,INSERT);
                }else if(PrevFree>m||(pos!=INF&&pos+len!=n+1)){
                    if(PrevFree>m)pos=1,len=PrevFree-1;
                    if(len>l+m+r)ans=-1;
                    else{
                        Fupdate(pos,len,DELETE);
                        Mupdate(ans=pos+max(0,len-r-m),m,INSERT);
                        Fupdate(pos,ans-pos,INSERT);
                        Fupdate(ans+m,pos+len-ans-m,INSERT);
                    }
                }else{
                    if(pos==INF)len=LastFree,pos=n+1-len;
                    if(len<m)ans=-1;
                    else{
                        Fupdate(pos,len,DELETE);
                        Mupdate(ans=pos,m,INSERT);
                    }
                }
                printf("%d\n",ans);
            }else{
                int k=cini()+1;
                if(k<=0||k>=mcnt[1])continue;
                int last=Mquery(k-1),curr=Mquery(k+0),next=Mquery(k+1);
                w=last+mlen[last];Fupdate(w,curr-w,DELETE);
                w=curr+mlen[curr];Fupdate(w,next-w,DELETE);
                w=last+mlen[last];Fupdate(w,next-w,INSERT);
                Mupdate(curr,mlen[curr],DELETE);
            }
        }
    }
    return 0;
}