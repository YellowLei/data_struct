#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int phi[50010];

void phi_table(int n)
{
    for(int i = 2;i <= n;i++)
        phi[i] = 0;
    phi[1] = 1;
    for(int i = 2;i <= n;i++)
    {
        if(!phi[i])
        {
            for(int j = i;j <= n;j +=i)
            {
                if(!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
}

int main()
{
    int n;
    phi_table(50010);
    while(scanf("%d",&n)&&n)
    {
        int ans = 0;
        for(int i = 2;i <= n;i++)
        {
            ans += phi[i];
        }
        printf("%d\n",2*ans+1);
    }
    return 0;
}

//超时
/*
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int phi(int n)
{
    int m = (int)sqrt(n+0.5);
    int ans = n;
    for(int i = 2;i <= m;i++)
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
    int n;
    while(scanf("%d",&n)&&n)
    {
        int ans = 0;
        for(int i = 2;i <= n;i++)
        {
            ans += phi(i);
        }
        printf("%d\n",2*ans+1);
    }
    return 0;
}
*/
