//1.���붥������ͱߵ�����
//2.����ߣ���3������洢��u[i],v[i],w[i]��ʾ��u[i]��v[i]��ȨֵΪw[i]
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
    //��ʼ��dis��ֵ��ʹ��Դ������ĵ��ֵΪinf��Դ��Ϊ0�Խ���ѭ��
	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}

	dis[1] = 0;

    //û�и�Ȩ��·�Ļ�����ൽһ������n-1�ֿ��ܣ��������n-1�ֻ�����ʹdis[i]��Ϊ��С˵���и�Ȩ��·
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
		//check����0��ʾdis[i]�Ѿ�ȫ������Сֵ
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
			printf("��ͼ���и�Ȩ��·");
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
