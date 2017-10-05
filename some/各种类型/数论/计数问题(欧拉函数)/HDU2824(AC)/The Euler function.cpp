#include <iostream>
#include <cstdio>

using namespace std;

int phi[3000005];

void phi_table(int n)
{
    for(int i = 2;i <= n;i++)
        phi[i] = 0;
    phi[1] = 1;
    for(int i = 2;i <= n;i++)
    {
        if(!phi[i])
        {
            for(int j = i;j <= n;j += i)
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
    int a,b;
    phi_table(3000000);
    while(~scanf("%d%d",&a,&b))
    {
        long long ans = 0;
        for(int i = a;i <= b;i++)
        {
            ans += phi[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
