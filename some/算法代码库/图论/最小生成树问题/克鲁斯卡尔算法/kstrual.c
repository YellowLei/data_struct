#include<stdio.h>
struct edge
{
	int u, v, w;
};//存储边的关系
struct edge e[10];
int n, m;
int f[7] = { 0 }, sum = 0, count = 0;

void quicksort(int left, int right)//快排
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

int getf(int v)//并查集寻找祖先数组
{
	if (f[v]!= v)
        f[v] = getf(f[v]);//递归,    //路径压缩
    return f[v];
}

int merge(int v, int u)//并查集合并两个子集合的函数
{
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2)//判断是否在一个集合当中
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

	quicksort(1, m);//对边的大小进行排序


	for (i = 1; i <= n; i++)
	{
		f[i] = i;
	}

	for (i = 1; i <= m; i++)//枚举每一条边
	{
		if (merge(e[i].u, e[i].v))//判断是否联通，为联通就选择这条边
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
