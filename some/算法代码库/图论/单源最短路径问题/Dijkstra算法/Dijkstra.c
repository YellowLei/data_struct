//1.初始化各条边的值，0或无穷(链接矩阵中所有的值)
//2.输入每条边的权值(输入的边的值存入链接矩阵中)
//3.初始化源点到各个相连边的距离
//4.判定并刷新
#include<stdio.h>
int main()
{
    int e[10][10], dis[10], book[10];
	int inf = 99999999;
	int i, j, n, m;
	int t1, t2, t3;
	int u, v, min;

	scanf("%d %d", &n, &m);//读入顶点和边的条数

	//从e[1][1]开始初始化
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;		//自己到自己为0
			}
			else e[i][j] = inf;    //正无穷
		}
	}//初始化各条边的值


	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2]=t3;
	}//输入每条边的权值

	for (i = 1; i <= n; i++)
	{
		dis[i] = e[1][i];
	}//初始化顶点1到各点的距离

	for (i = 1; i <= n; i++)
	{
		book[i] = 0;
	}
	book[1] = 1;//book数组用判定是否和顶点1直接相连

	for (i = 1; i <= n-1; i++)
	{
		min = inf;
		for (j = 1; j<= n; j++)
		{
			if (book[j] == 0 && dis[j] < min)//这里判断是否和1顶点相连，相连则在前面的初始化中使其值小于初始值inf
			{
				min = dis[j];   	//还没有遍历中的与1顶点相连的权最小的
				u = j;
			}
		}
		book[u] = 1;				//遍历出来后使其值为1，排除在下次遍历外

		for (v = 1; v <= n; v++)
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

	for (i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}
	return 0;
}
/*
//封装之后的
#include<stdio.h>
int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, minn;
int inf = 99999999;
void Dijkstra(int w)//w是源点
{

	for (i = 1; i <= n; i++)
	{
		dis[i] = e[w][i];
	}//初始化顶点1到各边的距离

	for (i = 1; i <= n; i++)
	{
		book[i] = 0;
	}
	book[w] = 1;//book数组用判定是否和顶点1直接相连

	for (i = 1; i <= n-1; i++)
	{
		minn = inf;
		for (j = 1; j<= n; j++)
		{
			if (book[j] == 0 && dis[j] < minn)//这里判断是否和1顶点相连，相连则在前面的初始化中使其值小于初始值inf
			{
				minn = dis[j];   	//还没有遍历中的与1顶点相连的权最小的
				u = j;
			}
		}
		book[u] = 1;				//遍历出来后使其值为1，排除在下次遍历外

		for (v = 1; v <= n; v++)
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
    scanf("%d %d", &n, &m);//读入顶点和边的条数

	//从e[1][1]开始初始化
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;		//自己到自己为0
			}
			else e[i][j] = inf;    //正无穷
		}
	}//初始化各条边的值


	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2]=t3;
	}//输入每条边的权值
    Dijkstra(1);
    for (i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}

    return 0;
}

*/

