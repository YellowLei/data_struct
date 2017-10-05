#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100010;
int nextt[maxn];
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
            ++k;
            ++j;
            if(p[j]!=p[k])
                nextt[j]=k;
            else
                nextt[j]=nextt[k];
        }
        else
            k=nextt[k];
    }
}
int KmpSearch(char* s, char* p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	GetNext(p);
	while (i < sLen)//这里只管主串有没有匹配完，当其匹配完成时，j是模式串前缀跟母串后缀最大的匹配长度
                    //当加上&&j<plen时，j时第一个匹配成功后的主串上的位置，可能在中间
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = nextt[j];
		}
	}
	//最后的j是模式串前缀跟母串后缀最大的匹配长度
    return j;
}
int main()
{
    while(~scanf("%s%s",s,p))
    {
        int j1=KmpSearch(s,p);
        int j2=KmpSearch(p,s);
        if(j1==j2)
        {
            if(strcmp(s,p)<0)
                printf("%s%s\n",s,p+j1);
            else printf("%s%s\n",p,s+j2);
        }
        else if(j1<j2)
            printf("%s%s\n",p,s+j2);
        else printf("%s%s\n",s,p+j1);
    }
}

//我想的超时
//int main()
//{
//    while(~scanf("%s%s",s,p))
//    {
//        memset(nextt,0,sizeof(nextt));
//        int slen=strlen(s);
//        int plen=strlen(p);
//        int len=slen+plen;
//        int lener;//较短的
//        if(slen<plen)
//            lener=slen;
//        else lener=plen;
//        //第二段接在第一段上
//        strcpy(s1,p);
//        strcat(s1,s);
//        GetNext(s1);
//        int m1=nextt[len];
//        if(m1>lener)
//            m1=lener;
//        for(int i=m1,j=slen;i<plen;i++,j++)
//        {
//            s[j]=p[i];
//        }
//
//        //第一段接在第二段上
//        strcpy(s2,s);
//        strcat(s2,p);
//        GetNext(s2);
//        int m2=nextt[len];
//        if(m2>lener)
//            m2=lener;
//        for(int i=m2,j=plen;i<slen;i++,j++)
//        {
//            p[j]=s[i];
//        }
//
//
//        slen=strlen(s);
//        plen=strlen(p);
//        if(slen<=plen)
//            printf("%s\n",s);
//        else printf("%s\n",p);
//        memset(s,'\0',sizeof(s));
//        memset(p,'\0',sizeof(p));
//    }
//}
