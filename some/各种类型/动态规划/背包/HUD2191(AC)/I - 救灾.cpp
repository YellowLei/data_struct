//HUD 2191
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int value[105],weight[105],number[105],f[105];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&value[i],&weight[i],&number[i]);
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=n;j>=value[i];j--)
            {
                for(int k=1;k<=number[i];k++)
                {
                    if(j>=k*value[i])
                    {
                        f[j]=max(f[j],f[j-k*value[i]]+k*weight[i]);
                    }
                }
            }
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
