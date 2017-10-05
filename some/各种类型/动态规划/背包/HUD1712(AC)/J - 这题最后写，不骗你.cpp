//HUD 1712
#include <iostream>
#include <cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[105][105],f[105];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m),m+n)
    {
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)
            {
                for(int k=1;k<=j;k++)   //把多重背包中一个个往里面加改为一次换一个
                {
                        f[j]=max(f[j],f[j-k]+a[i][k]);
                }
            }
        }
        printf("%d\n",f[m]);
    }
}
