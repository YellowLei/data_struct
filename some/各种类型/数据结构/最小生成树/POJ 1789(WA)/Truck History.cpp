#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=2005;
char a[maxn][10];
int dis[maxn],e[maxn][maxn],book[maxn],sum=0,minn,j;
int inf=999999;
int main()
{
    int n,i,j,k,Count;
    while(scanf("%d",&n),n)
    {
        sum=0;
        //输入字符串
        for(i=1;i<=n;i++)
        {
            scanf("%s",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                e[i][j]=0;
            }
        }
        for(i = 1; i <= n; i++)
        {
            for(j = i; j <= n; j++)
            {
                for(k=0; k<7; k++)
                {
                    if(a[i][k] != a[j][k])
                    {
                        e[i][j]++;
                        e[j][i]++;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            dis[i]=e[1][i];
        }
        for(i=1;i<=n;i++)
        {
            book[i]=0;
        }
        book[1]=1;
        for(Count=1;Count<n;Count++)
        {
            minn=inf;
            for(i=1;i<=n;i++)
            {
                if(book[i]==0&&dis[i]<minn)
                {
                    minn=dis[i];
                    j=i;
                }
            }
            book[j]=1;
            sum+=dis[j];
            for(k=1;k<=n;k++)
            {
                if(book[k]==0&&dis[k]>e[j][k])
                {
                    dis[k]=e[j][k];
                }
            }
        }
        printf("The highest possible quality is 1/%d.\n",sum);
    }
}
