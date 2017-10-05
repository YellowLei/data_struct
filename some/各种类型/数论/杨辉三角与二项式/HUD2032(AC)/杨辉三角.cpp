#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[31][31];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        a[1][1] = a[2][1] = a[2][2] = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= i;j++)
            {
                if(i != 1&&i != 2)
                    a[i][j] = a[i-1][j-1]+a[i-1][j];
                printf("%s%d",j == 1 ? "" : " ",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
