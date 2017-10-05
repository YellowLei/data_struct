//方法一，用库函数
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100005;
char s1[maxn],s2[maxn],s3[2*maxn];
int main()
{
    while(gets(s1)!=NULL&&gets(s2)!=NULL)
    {
        strcpy(s3,s1);
        strcat(s3,s1);
        if(strstr(s3,s2)!=0)//在s3中找s2
            printf("yes\n");
        else printf("no\n");
    }
}
