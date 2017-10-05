#include<stdio.h>
struct edge
{
	int u, v, w;
};//�洢�ߵĹ�ϵ
struct edge e[10];
int n, m;
int f[7] = { 0 }, sum = 0, count = 0;

void quicksort(int left, int right)//����
{
	int i, j;
	struct edge t;
	if (left > right)
		return;

	i = left;
	j = right;

	while (i != j)
	{
		while (e[j].w >= e[i].w&&i < j)
		{
			i++;
		}
		if (i < j)
		{
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		}
	}

	t = e[left];
	e[left] = e[i];
	e[i] = t;

	quicksort(left, i - 1);
	quicksort(i + 1, right);
}

int getf(int v)//���鼯Ѱ����������
{
	if (f[v]!= v)
        f[v] = getf(f[v]);//�ݹ�,    //·��ѹ��
    return f[v];
}

int merge(int v, int u)//���鼯�ϲ������Ӽ��ϵĺ���
{
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2)//�ж��Ƿ���һ�����ϵ���
	{
		f[t2] = t1;
		return 1;
	}
	return 0;
}

int main()
{
	int i;

	scanf("%d%d", &n, &m);

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &e[i].u, &e[i].v, &e[i].w);
	}

	quicksort(1, m);//�ԱߵĴ�С��������


	for (i = 1; i <= n; i++)
	{
		f[i] = i;
	}

	for (i = 1; i <= m; i++)//ö��ÿһ����
	{
		if (merge(e[i].u, e[i].v))//�ж��Ƿ���ͨ��Ϊ��ͨ��ѡ��������
		{
			count++;
			sum = sum + e[i].w;
		}

		if (count == n - 1)
			break;
	}

	printf("%d", sum);

	return 0;
}
