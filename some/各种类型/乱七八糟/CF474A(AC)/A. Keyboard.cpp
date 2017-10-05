
/*
//方法一，最快
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int r[30]={'p','v','x','s','w','d','f','g','u','h','j','k','n','b','i','o','0','e','a','r','y','c','q','z','t',';'};//对应着向右移的abc-z
	int l[30]={'s','n','v','f','r','g','h','j','o','k','l',';',',','m','p','a','w','t','d','y','i','b','e','c','u','x'};//对应着向左移的abc-z
    char a[110]={'\0'};
	char b[110]={'\0'};
	int L, i;
	char c;
	c=getchar();
	if(c=='R')
	{
		c=getchar();
		gets(a);
		L=strlen(a);
		for(i=0;i<L;i++)
		{
			if(a[i]>=97&&a[i]<=122)
				b[i]=r[a[i]-97];
			else
			{
				if(a[i]==';')b[i]='l';
				else if(a[i]==',')b[i]='m';
				else if(a[i]=='.')b[i]=',';
				else b[i]='.';
			}
		}
	}
	else
	{
		c=getchar();
		gets(a);
		L=strlen(a);
		for(i=0;i<L;i++)
		{
			if(a[i]>=97&&a[i]<=122)
				b[i]=l[a[i]-97];
			else
			{
				if(a[i]==',')b[i]='.';
				else b[i]='/';
			}
		}
	}
   for(i=0;i<L;i++)
	   printf("%c",b[i]);
   printf("\n");
    return 0;
}
//方法二
#include <iostream>
#include <cstring>
using namespace std;

char a[3][11]{"qwertyuiop","asdfghjkl;","zxcvbnm,./"};
void check(int &i,int &j,char ch)
{
    for(int ii=0;ii<3;ii++)
    {
        for(int jj=0;jj<11;jj++)
        {
            if(a[ii][jj]==ch)
            {
                i=ii;j=jj;break;
            }
        }
    }
}
int main()
{
    char s[105];
    char flag;
    while(cin>>flag>>s)
    {
    if(flag=='R')
    {
        int i,j;
        for(int k=0;k<strlen(s);k++)
        {
            if(s[k]!='q' && s[k]!='a' && s[k]!='z')
            {
                check(i,j,s[k]);
                s[k]=a[i][j-1];
            }
        }
    }
    if(flag=='L')
    {
        int i,j;
        for(int k=0;k<strlen(s);k++)
        {
            if(s[k]!='p' && s[k]!=';' && s[k]!='/')
            {
                check(i,j,s[k]);
                s[k]=a[i][j+1];
            }
        }
    }
    cout<<s<<endl;
    memset(s,0,sizeof(s));
    }
}

*/
//方法三
#include <iostream>
#include <cstdio>
using namespace std;
char s[]="qwertyuiopasdfghjkl;zxcvbnm,./";
int main()
{
	char ch,c;
	int i;
	while(scanf("%c",&ch)!=EOF)
	{
		getchar();
		while((c=getchar())!='\n')
		{
			for(i=0;s[i]!=c;i++);
			if(ch=='R') putchar(s[i-1]);
			else putchar(s[i+1]);
		}
		getchar();
	}
	return 0;
}

