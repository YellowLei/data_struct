#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int value[55],number[105],f[130000];
int main()
{
    int n;
    while(~scanf("%d",&n),n>=0)
    {
        int sum=0,half;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&value[i],&number[i]);
            sum+=(value[i]*number[i]);
        }
        half=sum/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=half;j>value[i];j--)
            {
                for(int k=1;k<=number[i];k++)
                {
                    if(j>=k*value[i])
                    {
                        f[j]=max(f[j],f[j-k*value[i]]+k*value[i]);
                    }
                }
            }
        }
        printf("%d %d\n",sum-f[half],f[half]);

    }

    return 0;
}
