#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char s[100000];
int main()
{
    int n,sum;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%s",s);
        sum=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='0'&&s[i]<='9')
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
