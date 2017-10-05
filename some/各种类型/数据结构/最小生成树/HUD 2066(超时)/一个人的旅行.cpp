/*
//加上一个家，使其与相连的城市链接，用一次Dij算法
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1005;
int T,S,D,s[maxn],d[maxn],e[maxn][maxn],dis[maxn],book[maxn],t1,t2,t3,minn,i,j,u,v,city=0;
int inf=999999;
int last=inf;
void Dijkstra(int w)//w是源点
{

	for (i = 1; i <= city; i++)
	{
		dis[i] = e[w][i];
	}//初始化顶点1到各边的距离

	for (i = 1; i <= city; i++)
	{
		book[i] = 0;
	}
	book[w] = 1;//book数组用判定是否和顶点1直接相连

	for (i = 1; i <= city-1; i++)
	{
		minn = inf;
		for (j = 1; j<= city; j++)
		{
			if (book[j] == 0 && dis[j] < minn)//这里判断是否和1顶点相连，相连则在前面的初始化中使其值小于初始值inf
			{
				minn = dis[j];   	//还没有遍历中的与1顶点相连的权最小的
				u = j;
			}
		}
		book[u] = 1;				//遍历出来后使其值为1，排除在下次遍历外

		for (v = 1; v <= city; v++)
		{
			if (e[u][v] < inf)//这里判断最短距离
			{
				if (dis[v]>dis[u] + e[u][v])
				{
					dis[v] = dis[u] + e[u][v];//更新
				}
			}
		}
	}
}
int main()
{
    while(scanf("%d%d%d",&T,&S,&D))
    {
        //初始化
        for(i=0;i<=maxn;i++)
        {
            for(j=0;j<=maxn;j++)
            {
                if(i==j)
                    e[i][j]=0;
                else
                    e[i][j]=inf;
            }
        }
        //输入路
        for(i=1;i<=T;i++)
        {
            scanf("%d%d%d",&t1,&t2,&t3);
            if(t1>city)
                city=t1;
            if(t2>city)
                city=t2;
            if(e[t1][t2]==inf||e[t1][t2]>t3)//处理重边
            {
                e[t1][t2]=t3;
                e[t2][t1]=t3;
            }
        }
        //输入相连的城市
        for(i=1;i<=S;i++)
        {
            scanf("%d",&s[i]);
            e[0][s[i]]=0;
        }
        //输入目的地
        for(i=1;i<=D;i++)
        {
            scanf("%d",&d[i]);
        }
        Dijkstra(0);
//        //以假设的0为源点
//        for(i=0;i<=city;i++)
//        {
//            dis[i]=e[0][i];
//        }
//        for (i = 0; i <= city; i++)
//        {
//            book[i] = 0;
//        }
//        book[0]=1;
//        for(i=0;i<=city-1;i++)
//        {
//            minn=inf;
//            for(j=0;j<=city;j++)
//            {
//                if(book[j]==0&&dis[j]<minn)
//                {
//                    minn=dis[j];
//                    u=j;
//                }
//            }
//            book[u]=1;
//            for(v=0;v<=city;v++)
//            {
//                if(e[u][v]<inf)
//                {
//                    if (dis[v]>dis[u] + e[u][v])
//                    {
//                        dis[v] = dis[u] + e[u][v];//更新
//                    }
//                }
//            }
//        }
        last=dis[d[1]];
        for(i=2;i<=D;i++)
        {
            if(last>dis[d[i]])
                last=dis[d[i]];
        }
        printf("%d\n",last);
    }
}
*/


//多次使用Dij算法
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1005;
int T,S,D,s[maxn],d[maxn],e[maxn][maxn],dis[maxn],book[maxn],t1,t2,t3,y,minn,u,city=0;
int inf=999999;
int last=inf;
int main()
{
    while(scanf("%d%d%d",&T,&S,&D))
    {
        memset(s,0,maxn);
        memset(d,0,maxn);
        memset(dis,0,maxn);
        memset(book,0,maxn);
        //初始化
        for(int i=1;i<=maxn;i++)
        {
            for(int j=1;j<=maxn;j++)
            {
                if(i==j)
                    e[i][j]=0;
                else
                    e[i][j]=inf;
            }
        }
        //输入路
        for(int i=1;i<=T;i++)
        {
            scanf("%d%d%d",&t1,&t2,&t3);
            if(t1>t2&&t1>city)
                city=t1;
            else if(t2>t1&&t2>city)
                city=t2;
            if(e[t1][t2]==inf||e[t1][t2]>t3)//处理重边
            {
                e[t1][t2]=t3;
                e[t2][t1]=t3;
            }
        }
        //输入相连的城市
        for(int i=1;i<=S;i++)
        {
            scanf("%d",&s[i]);
        }
        //输入目的地
        for(int i=1;i<=D;i++)
        {
            scanf("%d",&d[i]);
        }
        for(int w=1;w<=S;w++)
        {

//            y=s[w];//作源点
//            for(int i=1;i<=city;i++)
//            {
//                dis[i]=e[y][i];
//            }
//            for (int i = 1; i <= city; i++)
//            {
//                book[i] = 0;
//            }
//            book[y]=1;
//            for(int i=1;i<=city-1;i++)
//            {
//                minn=inf;
//                for(int j=1;j<=city;j++)
//                {
//                    if(book[j]==0&&dis[j]<minn)
//                    {
//                        minn=dis[j];
//                        u=j;
//                    }
//                }
//                book[u]=1;
//                for(int v=1;v<=city;v++)
//                {
//                    if(e[u][v]<inf)
//                    {
//                        if (dis[v]>dis[u] + e[u][v])
//                        {
//                            dis[v] = dis[u] + e[u][v];//更新
//                        }
//                    }
//                }
//            }
//            if(last>dis[d[1]])
//                last=dis[d[1]];
//            for(int i=2;i<=D;i++)
//            {
//                if(last>dis[d[i]])
//                    last=dis[d[i]];
//            }
        }
        printf("%d\n",last);
    }
}

