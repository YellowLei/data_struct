#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000005;
int nextt[maxn],N[maxn];
char s[maxn],p[maxn];
void GetNext(char* p)
{
    int plen=strlen(p);
    nextt[0]=-1;
    int j=0;
    int k=-1;
    while(j<plen)
    {
        if(k==-1||p[j]==p[k])
        {
            ++j;
            ++k;
            if(p[j]!=p[k])
                nextt[j]=k;
            else
                nextt[j]=nextt[k];
        }
        else
            k=nextt[k];
    }

}
int KMP(char* s,char* p,int i)
{
    int j=0;
    int plen=strlen(p);
    int slen=strlen(s);
    while(i<slen&&j<plen)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
            j=nextt[j];
    }
    if(j==plen)
        return i-j;
    else -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int w=0;w<n;w++)
    {
        scanf("%s",s);
        int slen=strlen(s);
        GetNext(s);
        int m=nextt[slen];
        if(m>slen/3)
            m=slen/3;
//        printf("m is %d\n",m);
        for(int i=0;i<m;i++)
        {
            p[i]=s[i];
        }
//        printf("p is %s\n",p);
        int ans=KMP(s,p,m);
        if(ans!=-1&&ans!=slen-m)
            N[w]=m;
        else N[w]=0;
//            printf("%d\n",m);
//        else printf("0\n");
    }
    for(int w=0;w<n;w++)
        printf("%d\n",N[w]);
    return 0;
}
