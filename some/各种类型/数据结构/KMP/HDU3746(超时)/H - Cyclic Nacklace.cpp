#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100005;
char s[maxn],s1[2*maxn];
int nextt[maxn];
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
            ++k;
            ++j;
            if(p[j]!=p[k])
                nextt[j]=k;
            else
                nextt[j]=nextt[k];

        }
        else
        {
            k=nextt[k];
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        int slen=strlen(s);
        GetNext(s);
        int u=nextt[slen];
//        printf("%d\n",u);
        strcpy(s1,s);
        for(int i=u,j=slen;i<slen;i++,j++)
        {
            s1[j]=s[i];
        }
        GetNext(s1);
        int len=strlen(s1);
        int v=nextt[len];
        if(slen%(slen-u)==0&&v!=slen)//本身是循环序列，排除只有一循环的情况
            printf("0\n");
        else if(v==slen&&u==0)
            {
                printf("%d\n",slen);
            }
        else printf("%d\n",slen-2*u);
    }
}
