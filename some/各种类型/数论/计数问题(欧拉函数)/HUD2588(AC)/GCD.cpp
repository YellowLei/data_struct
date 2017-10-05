//先求n的所有大于等于m的因子,ei
// ans=∑phi[n/ei]
//对于一个与ei互质且小于等于n/ei的正整数p来说，p*ei<=n,gcd(p*ei,n)=ei

//phi[n/ei]是1~n中的与n最大公约数是ei的个数
//phi[ei]是1~n中的与n最大公约数是n/ei的个数

//遍历每个ei的话会超时

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int phi(int n)
{
    int m = sqrt(n+0.5);
    int ans = n;
    for(int i = 2;i <= m;i++)
    {
        if(n % i == 0)
        {
            ans = ans / i * (i-1);
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    if(n > 1)
    {
        ans = ans / n * (n-1);
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ans = 0;
        for(int i = 1;i * i  <= n;i++)
        {
            //i为n的约数
            if(n % i == 0)
            {
                if(i >= m)
                    ans += phi(n / i);  //phi(n/i)是1~n中与n的最大公因子是i的个数

                //i * i <= n加这一步  优化
                //n / i 也是n的因子，可以优化很多
                if((n / i) != i&&(n / i) >= m)
                    ans += phi(i);      //phi(i)是1~n中与n的最大公因子是n/i的个数
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
