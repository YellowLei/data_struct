//我想的第二种
#include<iostream>
using namespace std;
const int maxn = 1010;
int N,M,X,a,b,t,d[maxn][maxn],e[maxn][maxn],dis[5][maxn],book[maxn],i,j,u,v,w=2,min1,max1;
int main()
{
    int inf=999999;
    cin>>N>>M>>X;
    //初始化各条边的值
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
        {
            if(i==j)
            {
                e[i][j]=0;
                d[i][j]=0;
            }
            else {
                    e[i][j]=inf;
                    d[i][j]=inf;
            }
        }
    //输入每条边的权值
    for(i=1;i<=M;i++)
    {
        cin>>a>>b>>t;
        e[a][b]=t;
        d[b][a]=t;
    }
    //初始化终点到各点的距离
    while(w)
    {
        if(w==1)
            for(i=1;i<=N;i++)
                for(j=1;j<=N;j++)
                e[i][j]=d[i][j];
        for(i=1;i<=N;i++)
        {
            dis[w][i]=e[X][i];
        }
        //book数组用于判定是否和终点相连
        for(i=1;i<=N;i++)
        {
            book[i]=0;
        }
        book[X]=1;

        for(i=1;i<=N-1;i++)
        {
            min1=inf;
            for(j=1;j<=N;j++)
            {
                if(book[j]==0&&dis[w][j]<min1)
                {
                    min1=dis[w][j];
                    u=j;
                }
            }
            book[u]=1;

            for(v=1;v<=N;v++)
            {
                if(e[u][v]<inf)
                {
                    if(dis[w][v]>dis[w][u]+e[u][v])
                    {
                        dis[w][v]=dis[w][u]+e[u][v];
                    }
                }
            }
        }
        w--;
    }
    max1=dis[1][i]+dis[2][i];
    for (i = 1; i <= N; i++)
	{
		if(max1<dis[1][i]+dis[2][i])
            max1=dis[1][i]+dis[2][i];
	}
	cout<<max1<<endl;
}



/*
//我想的第一种
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn= 100;
int main()
{
    int N,M,X,a,b,t,e[maxn][maxn],dis[maxn][maxn],book[maxn],c[maxn],i,j,u,v,w,min,max;
    int inf=999999;
    cin>>N>>M>>X;
    //初始化各条边的值
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
        {
            if(i==j)
                e[i][j]=0;
            else e[i][j]=inf;
        }
    //输入每条边的权值
    for(i=1;i<=M;i++)
    {
        cin>>a>>b>>t;
        e[a][b]=t;
    }
    //初始化某一点到各点的距离
    for(w=1;w<=N;w++)
    {
        for(i=1;i<=N;i++)
        {
            dis[w][i]=e[w][i];
        }

        //book数组用于判定是否和终点相连
        for(i=1;i<=N;i++)
        {
            book[i]=0;
        }
        book[w]=1;

        for(i=1;i<=N-1;i++)
        {
            min=inf;
            for(j=1;j<=N;j++)
            {
                if(book[j]==0&&dis[w][j]<min)
                {
                    min=dis[w][j];
                    u=j;
                }
            }
            book[u]=1;

            for(v=1;v<=N;v++)
            {
                if(e[u][v]<inf)
                {
                    if(dis[w][v]>dis[w][u]+e[u][v])
                    {
                        dis[w][v]=dis[w][u]+e[u][v];
                    }
                }
            }
        }

    }
    max=c[1];
    for(i=2;i<=N;i++)
    {
        if(c[i]>max)
            max=c[i];
    }
    cout<<max<<endl;
}
*/
