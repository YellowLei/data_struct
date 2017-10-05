//大整数加法
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1010;

int an1[maxn],an2[maxn];
char st1[maxn],st2[maxn];

int main ()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int k = 1;k <= T;k++)
    {
        scanf("%s",st1);
        scanf("%s",st2);
        memset(an1,0,sizeof(an1));
        memset(an2,0,sizeof(an2));

        int len1 = strlen(st1);
        int len2 = strlen(st2);
        int len = max(len1,len2);

        for(int i = 0,j = len1 - 1;j >= 0;j--)
            an1[i++] = st1[j] - '0';
        for(int i = 0,j = len2 - 1;j >= 0;j--)
            an2[i++] = st2[j] - '0';
        for(int i = 0;i <= len;i++)
        {
            an1[i] += an2[i];
            if(an1[i] >= 10)
            {
                an1[i] -= 10;
                an1[i + 1]++;
            }
        }
        printf("Case %d:\n",k);
        printf("%s + %s = ",st1,st2);
        if(an1[len - 1] == 0)
            len--;
        for(int i = len - 1;i >= 0;i--)
            printf("%d",an1[i]);
        if(len == 0)
            printf("0\n");
        else printf("\n");
        if(k < T)
            printf("\n");
    }
    return 0;
}

/*
#include<cstdio>
#include<iostream>
#include<string.h>

#define MAX 1100

using namespace std;

char a[MAX],b[MAX];
int c[MAX],d[MAX];

int change(char *s,int *aim)
{
    int i,j,value,flag=0,len;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        value=s[i]-'0';
        if(value!=0)
            flag=1;
        if(flag==1||s[i+1]=='\0')//将字符串转换为数字存入int数组。排除全0情况
            aim[j++]=value;
    }
    len=j-1;
    for(i=0,j=len;i<j;i++,j--)//将int数组倒置方便运算
    {
        value=aim[i];
        aim[i]=aim[j];
        aim[j]=value;
    }
    return len;

}
int main()
{
    int n,i,j,len,len1,len2,s;
    scanf("%d",&n);
    getchar();//注意用它接收回车字符
    for(i=1;i<=n;i++)
    {
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        scanf("%s%s",a,b);
        len1=change(a,c);
        len2=change(b,d);
        len=len1>len2?len1:len2;
        s=j=0;
        while(1)
        {
            if(s==0&&c[j]==0&&d[j]==0&&j>len)//判断运算是否结束
            {
                break;
            }
            c[j]=c[j]+d[j]+s;//模拟手算
            s=c[j]/10;      //s是进位
            c[j]=c[j]%10;
            j++;
        }
        len=j-1;
        printf("Case %d:\n",i);
        printf("%s + %s = ",a,b);//注意格式
        for(j=len;j>=0;j--)
            printf("%d",c[j]);
        printf("\n");
        if(i<n)
            printf("\n");
    }
    return 0;
}
*/
