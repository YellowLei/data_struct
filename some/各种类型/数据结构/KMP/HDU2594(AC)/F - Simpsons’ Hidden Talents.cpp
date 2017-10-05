#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=50010;
char s1[maxn<<1],s2[maxn];
int nextt[maxn<<1];
void GetNext(char* p)
{
    nextt[0]=-1;
    int k=-1,j=0;
    int plen=strlen(p);
    while(j<plen)
    {
        if(k==-1||p[j]==p[k])
        {
            ++k;
            ++j;
            nextt[j]=k;
        }
        else
            k=nextt[k];
    }
}
int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        int len1=strlen(s1);
        int len2=strlen(s2);

        strcat(s1,s2);
        GetNext(s1);

        int k=len1+len2;
        while(nextt[k]>len1 || nextt[k]>len2)
            k=nextt[k];

        if(nextt[k]==0)
             printf("0\n");
        else
        {
            for(int i=0;i<nextt[k];i++)
                printf("%c",s1[i]);
            printf(" %d\n",nextt[k]);
        }
    }
    return 0;
}
