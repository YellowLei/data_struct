#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int an[1005],sum[10005];
char st[105];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(sum,0,sizeof(sum));
        while(scanf("%s",st)&&st[0] != '0')
        {
            memset(an,0,sizeof(an));
            int len = strlen(st);
            for(int i = 0,j = len - 1;j >= 0;j--)
                an[i++] = st[j] - '0';
            for(int i = 0;i < 1005;i++)
            {
                sum[i] += an[i];
                if(sum[i] >= 10)
                {
                    sum[i] -= 10;
                    sum[i+1]++;
                }
            }
        }
        int i;
        for(i = 1005;i > 0;i--)
            if(sum[i])break;
        for(;i >= 0;i--)
            printf("%d",sum[i]);
        printf("\n");
        if(T!=0)
		printf("\n");
    }
    return 0;
}
