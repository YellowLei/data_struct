#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[210][100];
void Init()
{
    memset(a,0,sizeof(a));
    a[1][0] = 1;
    a[2][0] = 2;
    for(int i = 3;i <= 220;i++)
    {
        for(int j = 0;j < 100;j++)
        {
            a[i][j] += a[i-1][j] + a[i-2][j];
            if(a[i][j] >= 10)
            {
                a[i][j] -= 10;
                a[i][j+1]++;
            }
        }
    }
}

int main()
{
    Init();
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        for(i = 99;i >= 0;i--)
            if(a[n][i])break;
        for(;i >= 0;i--)
            printf("%d",a[n][i]);
        printf("\n");
    }
    return 0;
}

/*
//题目数据为大整数，这里不够输出,
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int c[210][210];
int main()
{
    int n;
    for(int i = 0 ;i <= 210 ;i++)
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1;j <= i;j++)
        {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    while(~scanf("%d",&n))
    {
        memset(c,0,sizeof(c));
        int ans = 0;
        for(int i = 0;i <= n/2;i++)
        {
            ans += c[n - i][i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/
