//优化后
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int vis[10010];

//求小于n的素数
void get_prime(int n)
{
    int m = sqrt(n+0.5);
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
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a,b;
        memset(vis,0,sizeof(vis));
        get_prime(n);
        for(int i = 1;i <= n/2;i++)
        {
            if(!vis[i]&&!vis[n-i])
            {
                a = i;
                b = n-i;
            }
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}

/*
//优化前
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int prime_number[10010];

//求小于n的素数
int get_prime(int n)
{
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    int m = sqrt(n+0.5);
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
    int cnt = 0;
    for(int i = 2;i <= n;i++)
    {
        if(!vis[i])
            prime_number[++cnt] = i;
    }
    return cnt;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a,b;
        memset(prime_number,0,sizeof(prime_number));
        int num = get_prime(n);
        for(int i = 1;i < num;i++)
        {
            for(int j = num;j >= i;j--)
            {
                if(prime_number[i] + prime_number[j] == n)
                {
                    a = prime_number[i];
                    b = prime_number[j];
                }
            }
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}
*/
