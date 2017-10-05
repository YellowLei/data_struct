#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

const int maxn=1010;

int f[maxn],sg[maxn],vis[maxn];

void getsg(int n)
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(j=1;f[j]<=i;j++)
            vis[sg[i-f[j]]]=1;
        for(j=0;j<=n;j++)
        {
            if(vis[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}

int main()
{
    int m,n,p;
    f[0]=f[1]=1;
    for(int i=2;i<=16;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    getsg(maxn);
    while(~scanf("%d%d%d",&m,&n,&p))
    {
        if(m==0&&n==0&&p==0)
            break;
        int ans=(sg[m]^sg[n]^sg[p]);
        if(ans!=0)
            printf("Fibo\n");
        else
            printf("Nacci\n");
    }
    return 0;
}
