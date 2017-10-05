#include <cstdio>
#include <iostream>

using namespace std;

long long a[21];

int main()
{
    int T,n;
    scanf("%d",&T);
    a[1]=a[2]=a[3]=1;
    for(int i = 4;i <= 20;i++)
    {
        a[i] = a[i-1] * (i-1);
    }
    while(T--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
/*
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n == 1||n == 2||n ==3)
            printf("1\n");
        else
        {
            long long ans = 1;
            for(int i = 2;i <= n-1;i++)
            {
                ans *= i;
            }
            printf("%lld\n",ans/2);
        }
    }
    return 0;
}

*/
