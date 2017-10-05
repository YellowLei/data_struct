#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=200010;
char s[maxn],p[maxn];
int nextt[maxn],sum,pos,v,a[maxn];
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
    int ans=0;
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
            a[v]=i-j;
            v++;
            j=0;
        }
    }
    return ans;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        pos=0;
        memset(nextt,0,sizeof(nextt));
        scanf("%d",&m);
        getchar();
        for(int i=0;i<m;i++)
        {
            scanf("%c",&s[i]);
        }
        getchar();
        p[0]=s[0];
        pos=KmpSearch(s,p);
        sum=pos;
//        for(int i=0;i<pos;i++)
//            printf("%d ",a[i]);
//        printf("\n");
        for(int i=1;i<m/2;i++)
        {
            for(int j=0;j<pos;j++)
            {
                if(s[i]==s[a[j]+i]&&a[j]!=-1&&a[j]+i<m)
                    sum++;
                if(s[i]!=s[a[j]+i])
                    a[j]=-1;
            }
        }
//        for(int i=1;i<=m/2;i++)
//        {
//            memset(p,0,sizeof(p));
//            memset(nextt,0,sizeof(nextt));
//            for(int j=0;j<i;j++)
//                p[j]=s[j];
//            pos=KmpSearch(s,p);
//            sum+=pos;
//        }
        sum=sum+m-m/2;
        printf("%d\n",sum%1007);
    }
    return 0;
}
