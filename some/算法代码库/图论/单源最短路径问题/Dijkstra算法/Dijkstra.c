//1.��ʼ�������ߵ�ֵ��0������(���Ӿ��������е�ֵ)
//2.����ÿ���ߵ�Ȩֵ(����ıߵ�ֵ�������Ӿ�����)
//3.��ʼ��Դ�㵽���������ߵľ���
//4.�ж���ˢ��
#include<stdio.h>
int main()
{
    int e[10][10], dis[10], book[10];
	int inf = 99999999;
	int i, j, n, m;
	int t1, t2, t3;
	int u, v, min;

	scanf("%d %d", &n, &m);//���붥��ͱߵ�����

	//��e[1][1]��ʼ��ʼ��
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;		//�Լ����Լ�Ϊ0
			}
			else e[i][j] = inf;    //������
		}
	}//��ʼ�������ߵ�ֵ


	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2]=t3;
	}//����ÿ���ߵ�Ȩֵ

	for (i = 1; i <= n; i++)
	{
		dis[i] = e[1][i];
	}//��ʼ������1������ľ���

	for (i = 1; i <= n; i++)
	{
		book[i] = 0;
	}
	book[1] = 1;//book�������ж��Ƿ�Ͷ���1ֱ������

	for (i = 1; i <= n-1; i++)
	{
		min = inf;
		for (j = 1; j<= n; j++)
		{
			if (book[j] == 0 && dis[j] < min)//�����ж��Ƿ��1������������������ǰ��ĳ�ʼ����ʹ��ֵС�ڳ�ʼֵinf
			{
				min = dis[j];   	//��û�б����е���1����������Ȩ��С��
				u = j;
			}
		}
		book[u] = 1;				//����������ʹ��ֵΪ1���ų����´α�����

		for (v = 1; v <= n; v++)
		{
			if (e[u][v] < inf)//�����ж���̾���
			{
				if (dis[v]>dis[u] + e[u][v])
				{
					dis[v] = dis[u] + e[u][v];//����
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
//��װ֮���
#include<stdio.h>
int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, minn;
int inf = 99999999;
void Dijkstra(int w)//w��Դ��
{

	for (i = 1; i <= n; i++)
	{
		dis[i] = e[w][i];
	}//��ʼ������1�����ߵľ���

	for (i = 1; i <= n; i++)
	{
		book[i] = 0;
	}
	book[w] = 1;//book�������ж��Ƿ�Ͷ���1ֱ������

	for (i = 1; i <= n-1; i++)
	{
		minn = inf;
		for (j = 1; j<= n; j++)
		{
			if (book[j] == 0 && dis[j] < minn)//�����ж��Ƿ��1������������������ǰ��ĳ�ʼ����ʹ��ֵС�ڳ�ʼֵinf
			{
				minn = dis[j];   	//��û�б����е���1����������Ȩ��С��
				u = j;
			}
		}
		book[u] = 1;				//����������ʹ��ֵΪ1���ų����´α�����

		for (v = 1; v <= n; v++)
		{
			if (e[u][v] < inf)//�����ж���̾���
			{
				if (dis[v]>dis[u] + e[u][v])
				{
					dis[v] = dis[u] + e[u][v];//����
				}
			}
		}
	}
}
int main()
{
    scanf("%d %d", &n, &m);//���붥��ͱߵ�����

	//��e[1][1]��ʼ��ʼ��
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;		//�Լ����Լ�Ϊ0
			}
			else e[i][j] = inf;    //������
		}
	}//��ʼ�������ߵ�ֵ


	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2]=t3;
	}//����ÿ���ߵ�Ȩֵ
    Dijkstra(1);
    for (i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}

    return 0;
}

*/

