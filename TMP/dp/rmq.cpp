int f[100005],Q[100005][17],n;
inline int func(int a,int b){return a>b?a:b;}
void rmqinit(){
    for(int i=1;i<=n;i++)Q[i][0]=f[i];
    int k=1;while(1<<k<=n)k++;
    for(int j=1;j<k;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            Q[i][j]=func(Q[i][j-1],Q[i+(1<<(j-1))][j-1]);
}
int rmq(int l,int r){if(l>r)return 0;
    int k=0;while(1<<k+1<=r-l+1)k++;
    return func(Q[l][k],Q[r-(1<<k)+1][k]);
}