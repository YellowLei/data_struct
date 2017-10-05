#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    int n,q,a[1010],l,r;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&q);
        for(int i = 0;i < q;i++)
        {
            scanf("%d%d",&l,&r);
            int maxn = a[l];
            for(int j = l + 1;j <= r;j++)
            {
               if(a[j] >= maxn)
                maxn = a[j];
            }
            printf("%d\n",maxn);
        }
    }
    return 0;
}
