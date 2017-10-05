#include <iostream>
#include <cstdio>

//如果加了第n个人我们不用他 那么总数为f[n-1]
//如果我们用了第n个人 共有n-1个人可以和他结合总数为(n-1)*f[n-2]
//所以公式f[n]=f[n-1]+(n-1)*f[n-2]
using namespace std;

long long f[1000005];

int main()
{
    int T,n;
    scanf("%d",&T);
    f[1] = 1;f[2] = 2;
    for(int i = 3;i <= 1000000;i++)
    {
        f[i] = (f[i - 1] + (i - 1) * f[i - 2]) % 1000000007;
    }
    for(int t = 1;t <= T;t++)
    {
        scanf("%d",&n);
        printf("Case #%d:\n%d\n",t,f[n]);
    }
    return 0;
}
