#include<iostream>
#include<cstdio>
#include <cstdlib>
const int maxn=1005;
int n,e[maxn][maxn],book[maxn],dis[maxn],sum=0,minn,j;
char m[100];
int inf=9999999;
using namespace std;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        if(i==j)
            e[i][j]=0;
        else
            e[i][j]=inf;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            scanf("%s",m);
            if(m[0]=='x')
            e[i][j]=e[j][i]=inf;
            else
            e[i][j]=e[j][i]=atoi(m);
        }
    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            printf("%d ",e[i][j]);
//        }
//        printf("\n");
//    }
    for(int i=1;i<=n;i++)
    {
        dis[i]=e[1][i];
    }
    for (int i = 1; i <= n; i++)
	{
		book[i] = 0;
	}
    book[1]=1;
    for(int Count=1;Count<n;Count++)
    {
        minn=inf,j=0;
        for(int i=1;i<=n;i++)
        {
            if(book[i]==0&&dis[i]<minn)
            {
                minn=dis[i];
                j=i;
            }
        }
        book[j]=1;
        for(int i=1;i<=n;i++)
        {
            if(book[i]==0&&dis[i]>e[j][i]+dis[j])
            {
                dis[i]=e[j][i]+dis[j];
            }
        }
    }
    printf("%d",minn);
}
