#include<bits/stdc++.h>
int main()
{
    int n;
    scanf("%d",&n);
    int*ptr=new int[n];
    for(int i=0;i<n;i++)
        scanf("%d",ptr+i);
    int cnt=0;
    for(int i=0;i<n;i++)
        if(ptr[i]!=i+1)
            std::swap(ptr[i],ptr[ptr[i]-1]),
            cnt++,i--;
    puts((cnt+3*n)&1?"Um_nik":"Petr");
    delete ptr;
    return 0;
}