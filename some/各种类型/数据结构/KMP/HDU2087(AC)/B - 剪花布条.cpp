#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1005;
int nextt[maxn],sum,ans;
char n[2*maxn],s[maxn],p[maxn];
void GetNext(char* p)
{
    int plen=strlen(p);
    nextt[0]=-1;
    int j=0;
    int k=-1;
    while(j<plen-1)
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
int KmpSearch(char* s,char* p)
{
    int i=0;
    int j=0;
    int slen=strlen(s);
    int plen=strlen(p);
    GetNext(p);
    while(i<slen&&j<plen)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else{
            j=nextt[j];
        }
        if(j>=plen)
        {
            ans++;
            j=0;
        }
    }
    return ans;

}
int main()
{
    int i,j,center;
    while(scanf("%s",s),s[0]!='#')
    {
        scanf("%s",p);
        sum=0;
        ans=0;
        memset(nextt,0,sizeof(nextt));
        sum=KmpSearch(s,p);
        printf("%d\n",sum);
    }
}
