#include<stdio.h>
int main()
{
	int n, m, i, j, k, min, t1, t2, t3;
	int e[7][7], dis[7], book[7] = { 0 };
	int inf = 99999999;
	int count = 0, sum = 0;

	scanf("%d%d", &n, &m);
	//初始化连接矩阵
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (i == j) e[i][j] = 0;
			else e[i][j] = inf;
		}
	}

    //输入边
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);

		e[t1][t2] = t3;
		e[t2][t1] = t3;
	}
    //到源点的距离
	for (i = 1; i <= n; i++)
	{
		dis[i] = e[1][i];
	}

	book[1] = 1;//开始把顶点加入生成树当中
	count++;
	while (count < n)
	{
		min = inf;
		for (i = 1; i <= n; i++)
		{
			if (book[i] == 0 && dis[i] < min)
			{
				min = dis[i];
				j = i;
			}
		}
		book[j] = 1;
		count++;
		sum = sum + dis[j];//把j加入到生成树里

		for (k = 1; k <= n; k++)//以j为顶点扫描距离生成树最近的点
		{
			if (book[k] == 0 && dis[k] > e[j][k])
			{
				dis[k] = e[j][k];//更新
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}
