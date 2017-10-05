#include <iostream>
#include <cstdio>

using namespace std;

int ss(int n)
{
    for(int i = 2 ;i * i <= n;i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int hh(int n)
{
    int maxn = n,minn = 0;
    while(maxn > 0)
    {
        minn = minn * 10 + maxn % 10;
        maxn /= 10;
    }
    if(minn == n)
        return 1;
    return 0;
}
int main (void)
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n > m)
        {
            n += m;
            n = n - m;
            n -= m;
        }
        for(int i = n;i <= 9989899;i++)//打表确定范围，在9989899后没有满足的
        {
            if(hh(i)&&ss(i))
                printf("%d\n",i);
        }
        printf("\n");
    }
    return 0;
}
/*
//超内存
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int vis[100000005];

void fac(int n)
{
    int m = sqrt(n+0.5);
    //找到素数
    for(int i = 2;i <= m;i++)
    {
        if(!vis[i])
        {
            for(int j = i * i;j <= n ;j += i)
            {
                vis[j] = 1;
            }
        }
    }
    //在素数中去掉不是回文数的数
    for(int i = 2;i <= n;i++)
    {
        int minn = 0;
        int maxn = i;
        if(!vis[i])
        {
            while(maxn > 0)
            {
                //minn等于把该数倒过来写
                minn = minn * 10 + maxn % 10;
                maxn = maxn / 10;
            }
            if(minn != i)
                vis[i] = 1;
        }
    }
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,0,sizeof(vis));
        fac(m);
        for(int i = n;i <= m;i++)
        {
            if(!vis[i])
                printf("%d\n",i);
        }
        printf("\n");
    }
    return 0;
}
*/
