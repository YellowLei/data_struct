#include<iostream>
#include<cstdio>
#include<cmath>
const int maxn=105;
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int book[maxn],i,j,u,v,k,Count = 0;
        double x[maxn],y[maxn],z[maxn],r[maxn],e[maxn][maxn],dis[maxn],minn,r1;
        int inf=999999;
        double sum = 0;
        //初始化连接矩阵
        for (i = 1; i <=n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j) e[i][j] = 0;
                else e[i][j] = inf;
            }
        }
        //输入点
        for(i=1;i<=n;i++)
        {
            scanf("%lf %lf %lf %lf",&x[i],&y[i],&z[i],&r[i]);
        }
        //边
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                e[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]))-r[i]-r[j];
                if(e[i][j]<0)
                    e[i][j]=0;
            }
        }
        //到源点的距离
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
            sum=sum+dis[j];
            for(k=1;k<=n;k++)
            {
                if(book[k]==0&&dis[k]>e[j][k])
                {
                    dis[k]=e[j][k];
                }
            }
        }
        printf("%.3lf\n",sum);
    }
}
