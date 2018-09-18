//global array default next[1]=0,needn't to init
char s[1000005],t[10005];
int next[10005],slen,tlen;
void getnext(char*t,int tlen){
    for(int i=1;i<=tlen;i++){
        int j=next[i];
        while(j&&t[i]!=t[j])j=next[j];
        next[i+1]=t[i]==t[j]?j+1:0;
    }
}
int kindex(char*s,char*t,int slen){
    for(int i=0,j=0;i<slen;i++){
        while(j&&s[i]!=t[j])j=next[j];
        if(s[i]==t[j])j++;
        if(j==slen)return i-m+2;
    }return -1;
}
int kcount(char*s,char*t,int slen){
    int ans=0;
    for(int i=0,j=0;i<slen;i++){
        while(j&&s[i]!=t[j])j=next[j];
        if(s[i]==t[j])j++;
        if(j==slen)ans++;
    }return ans;
}

const int maxn=100010; //�ַ����������ֵ
int next[maxn],ex[maxn]; //ex���鼴Ϊextend���� ex[i]��ʾT��S[i,n-1]�������ǰ׺
//Ԥ�������next����
void getnext(char *str)
{
    int i=0,j,po,len=strlen(str);
    next[0]=len;//��ʼ��next[0]
    while(str[i]==str[i+1]&&i+1<len)//����next[1]
        i++;
    next[1]=i;
    po=1;//��ʼ��po��λ��
    for(i=2;i<len;i++)
    {
        if(next[i-po]+i<next[po]+po)//��һ�����������ֱ�ӵõ�next[i]��ֵ
            next[i]=next[i-po];
        else//�ڶ��������Ҫ����ƥ����ܵõ�next[i]��ֵ
        {
            j=next[po]+po-i;
            if(j<0)j=0;//���i>po+next[po],��Ҫ��ͷ��ʼƥ��
            while(i+j<len&&str[j]==str[j+i])//����next[i]
                j++;
            next[i]=j;
            po=i;//����po��λ��
        }
    }
}
//����extend����
void exkmp(char *S,char *T)
{
    int i=0,j,po,len=strlen(S),l2=strlen(T);
    getnext(T);//�����Ӵ���next����
    while(S[i]==T[i]&&i<l2&&i<len)//����ex[0]
        i++;
    ex[0]=i;
    po=0;//��ʼ��po��λ��
    for(i=1;i<len;i++)
    {
        if(next[i-po]+i<ex[po]+po)//��һ�������ֱ�ӿ��Եõ�ex[i]��ֵ
            ex[i]=next[i-po];
        else//�ڶ��������Ҫ����ƥ����ܵõ�ex[i]��ֵ
        {
            j=ex[po]+po-i;
            if(j<0)j=0;//���i>ex[po]+po��Ҫ��ͷ��ʼƥ��
            while(i+j<len&&j<l2&&S[j+i]==T[j])//����ex[i]
                j++;
            ex[i]=j;
            po=i;//����po��λ��
        }
    }
}
�ַ�������С��ʾ��,���Ƕ���һ���ַ���,���Խ��������һλ�ŵ���һλ��,��������,һ����strlen�ֱ���
����:s="00ab"
�����У�ʡ�����ţ�b00a ab00 0ab0 ����00ab һ��4��
��ô�ҵ������ֵ�����С��һ��,�õ��㷨����minr,��ô�ҵ������ֵ�������һ��,�õ��㷨����maxr
namespace
{
    bool mmr=false;
}
int minr(char s[])
{
    if(mmr==false)
    {
        memcpy(s+len,s,sizeof(char)*len);
        s[len*2]=0;//array s must at least have double room
        mmr=true;
    }
    int i=0,j=1;
    while(i<len&&j<len)
    {
        int k=0;
        while(s[i+k]==s[j+k]&&k<len)
            k++;
        if(k==len)
            break;
        if(s[i+k]>s[j+k])
            i=i+k+1>j+1?i+k+1:j+1;
        else
            j=j+k+1>i+1?j+k+1:i+1;
    }
    return i<j?i:j;
}
int maxr(char s[])
{
    if(mmr==false)
    {
        memcpy(s+len,s,sizeof(char)*len);
        s[len*2]=0;//array s must at least have double room
        mmr=true;
    }
    int i=0,j=1;
    while(i<len&&j<len)
    {
        int k=0;
        while(s[i+k]==s[j+k]&&k<len)
            k++;
        if(k==len)
            break;
        if(s[i+k]<s[j+k])
            i=i+k+1>j+1?i+k+1:j+1;
        else
            j=j+k+1>i+1?j+k+1:i+1;
    }
    return i<j?i:j;
}