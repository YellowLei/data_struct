#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int num[2000000];
int change(char str[])
{
    int len = strlen(str);
    int ans = 0;
    for(int i = 0;i < len;i++)
    {
        ans *= 10;
        if(str[i]=='a'||str[i]=='b'||str[i]=='c')
			ans+=2;
        else if(str[i]=='d'||str[i]=='e'||str[i]=='f')
			ans+=3;
        else if(str[i]=='g'||str[i]=='h'||str[i]=='i')
			ans+=4;
        else if(str[i]=='m'||str[i]=='n'||str[i]=='o')
			ans+=6;
        else if(str[i]>='p'&&str[i]<='s')
			ans+=7;
        else if(str[i]>='t'&&str[i]<='v')
			ans+=8;
        else if(str[i]>='w'&&str[i]<='z')
			ans+=9;
        else ans+=5;
    }
    return ans;
}

int a[10000];
char str[20];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(num,0,sizeof(num));
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int  i = 0;i < m;i++)
        {
            scanf("%s",str);
            num[change(str)]++;
        }
        for(int i = 0;i < n;i++)
        {
            printf("%d\n",num[a[i]]);
        }
    }
    return 0;
}
