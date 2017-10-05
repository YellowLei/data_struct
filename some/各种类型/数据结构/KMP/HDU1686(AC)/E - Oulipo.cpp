#include<stdio.h>
#include<string.h>
int next[10005];
char t[1000010],w[10005];
void get_next(int len)
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<len)
    {
        if(j==-1||w[i]==w[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
int kmp()
{
    int len1=strlen(t),len2=strlen(w);
    get_next(len2);
    int i=0,j=0;
    int ans=0;
    while(i<len1)
    {
        if(j==-1||t[i]==w[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
        if(j==len2)
        {
            ans++;
            j=next[j];
        }
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(w,'\0',sizeof(w));
        memset(t,'\0',sizeof(t));
        scanf("%s",w);
        scanf("%s",t);
        int ans=kmp();
        printf("%d\n",ans);
    }
    return 0;
}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//const int maxn=10005;
//int nextt[maxn];
//char s[2*maxn],p[maxn];
//void GetNext(char* p)
//{
//    int plen=strlen(p);
//    nextt[0]=-1;
//    int j=0;
//    int k=-1;
//    while(j<plen-1)
//    {
//        if(k==-1||p[j]==p[k])
//        {
//            ++k;
//            ++j;
//            if(p[j]!=p[k])
//                nextt[j]=k;
//            else
//                nextt[j]=nextt[k];
//
//        }
//        else
//        {
//            k=nextt[k];
//        }
//    }
//}
//int KMP(char* s,char* p)
//{
//    int i=0;
//    int j=0;
//    int ans=0;
//    int plen=strlen(p);
//    int slen=strlen(s);
//    GetNext(p);
//
//    while(i<slen&&j<plen)
//    {
//        if(j==-1||p[j]==s[i])
//        {
//            i++;
//            j++;
//        }
//        else
//            j=nextt[j];
//        if(j=plen)
//        {
//            ans++;
//            i=i-nextt[j];
//            j=0;
//        }
//    }
//    return ans;
//
//}
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++)
//    {
//        int sum=0;
//        memset(nextt,0,sizeof(nextt));
//        memset(p,'\0',sizeof(p));
//        memset(s,'\0',sizeof(s));
//        scanf("%s",p);
//        scanf("%s",s);
//        sum=KMP(s,p);
//        printf("%d\n",sum);
//    }
//}
