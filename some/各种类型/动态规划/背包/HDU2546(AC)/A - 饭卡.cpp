#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m;
int value[1005],weight[1005],f[1005];

int getMax(int a,int b)
{
    return a>=b?a:b;
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        int high=1;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&value[i]);
            weight[i]=value[i];
            if(value[i]>value[high])
                high=i;
        }
        weight[high]=999999;
        scanf("%d",&m);

        for(int i=1;i<=n;i++)
        {
            for(int j=m-5;j>=weight[i];j--)
            {
                f[j]=getMax(f[j],f[j-weight[i]]+value[i]);
            }
        }
        if(m<5)
            printf("%d\n",m);
        else
            printf("%d\n",m-f[m-5]-value[high]);
    }
    return 0;
}
