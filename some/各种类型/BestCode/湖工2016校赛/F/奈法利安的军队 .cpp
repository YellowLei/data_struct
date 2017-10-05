//超时
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    int a[100005],b;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int  i = 1;i <= m;i++)
    {
        scanf("%d",&b);
        for(int j = 0;j < n;j++)
        {
            if(b <= a[j])
            {
                printf("%d\n",j + 1);
                break;
            }
        }
    }
    return 0;
}
