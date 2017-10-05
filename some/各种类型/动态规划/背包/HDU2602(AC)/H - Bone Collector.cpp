#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int weight[1005],value[1005],f[1005];
    int n,v,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&v);
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
            scanf("%d",&value[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&weight[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=v;j>=weight[i];j--)
            {
                f[j]=max(f[j],f[j-weight[i]]+value[i]);
            }
        }
        printf("%d\n",f[v]);
    }
    return 0;
}
