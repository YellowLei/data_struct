#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int mod = 1000000007;

long long phi(long long n)
{
    long long m = sqrt(n+0.5);
    long long ans = n;
    for(long long i = 2;i <= m;i++)
    {
        if(n % i ==0)
        {
            ans = ans / i * (i-1);
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)
        ans = ans / n * (n-1);
    return ans;
}

int main()
{
    long long n,k;
    while(~scanf("%I64d%I64d",&n,&k))
    {
        long long ans = 0;
        if(n == 1)
            ans = 1;
        else
        {
            if(k > 1)
                ans = 0;
            if(k == 2)
                ans = 1;
            if(k == 1)
            {
                for(long long i = 1;i * i <= n;i++)
                {
                    if(n % i ==0)
                    {
                        if(i * i == n) //注意不用乘2
                            ans += phi(n / i) * phi(i); //phi(n/i)是1~n中与n的最大公因子是i的个数
                        else ans += 2*phi(n / i) * phi(i);//phi(i)是1~n中与n的最大公因子是n/i的个数
                        ans %= mod;
                    }
                }

            }
        }
        printf("%I64d\n",ans % mod);
    }
    return 0;
}
