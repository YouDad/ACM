/*
    思路:f[i]=f[i-2]+f[i-1]
*/
#include<stdio.h>
int f[100]={0,1,5};
void init()
{
    for(int i=3;i<100;i++)
        f[i]=f[i-1]+(f[i-2]+1)*i*i;
}
int main(){
    init();
    int n;
    while(~scanf("%d",&n))
    {

    }
    return 0;
}