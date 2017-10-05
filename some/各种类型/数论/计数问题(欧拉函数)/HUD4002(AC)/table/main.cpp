#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

const int maxn = 1000;
int vis[100000];
int prime[maxn];
int ans[maxn][maxn];
void prime_table(int n)
{
    int m = sqrt(n+0.5);
    memset(vis,0,sizeof(vis));
    for(int i = 2;i <= m;i++)
    {
        if(!vis[i])
        {
            for(int j = i*i;j <= n;j += i)
            {
                vis[j] = 1;
            }
        }
    }
    for(int i = 1,j = 0;i <= n;i++)
    {
        if(vis[i] == 0)
        {
            prime[j++] = i;
        }
    }
}

void multiply(int a[],int n)
{
    int vis = 0;
    for(int i = 0;i <= maxn;i++)
    {
        vis += a[i] * n;
        a[i] = vis % 10;
        vis /= 10;
    }
}
//打表
void table(int n)
{
    ans[0][0] = 2;
    prime_table(500);
    for(int i = 1;i <= n;i++)
    {
        memcpy(ans[i],ans[i-1],maxn*sizeof(int));
        multiply(ans[i],prime[i+1]);
    }
}

int main ()
{
    freopen("output.txt","w",stdout);
    table(100);
    for(int i = 0;i <= 52;i++)
    {
        int j;
        for(j = 100;j >= 0;j--)
            if(ans[i][j] != 0)break;
        if(j >= 0)
            printf("\"");
        for(;j >= 0;j--)
            printf("%d",ans[i][j]);
        printf("\",\n");
    }
    return 0;
}
