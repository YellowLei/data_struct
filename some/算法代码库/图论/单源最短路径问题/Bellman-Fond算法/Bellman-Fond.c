//1.输入顶点个数和边的条数
//2.输入边，用3个数组存储，u[i],v[i],w[i]表示从u[i]到v[i]的权值为w[i]
//3.
#include<stdio.h>
int main()
{
	int dis[10], bak[10], i, j, k, n, m, u[10], v[10], w[10], check, flag;
	int inf = 99999999;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	}
    //初始化dis的值，使除源点以外的点的值为inf，源点为0以进入循环
	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}

	dis[1] = 0;

    //没有负权回路的话，最多到一个点有n-1种可能，如果进行n-1种还不能使dis[i]变为最小说明有负权回路
	for (k = 1; k <= n - 1; k++)
	{
		check = 0;
		for (i = 1; i <=m; i++)
		{
			if (dis[v[i]] > dis[u[i]] + w[i])
			{
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;
			}
		}
		//check等于0表示dis[i]已经全部是最小值
		if (check == 0)
		{
			break;
		}
	}

	flag = 0;
	for (i = 1; i <= m; i++)
	{
		if (dis[v[i]] > dis[u[i]] + w[i])
		{
			flag = 1;
		}
		if (flag == 1)
		{
			printf("此图含有负权回路");
		}
		else
		{
			for (i = 1; i <= n; i++)
			{
				printf("%d ", dis[i]);
			}
		}

	}
	return 0;
}
