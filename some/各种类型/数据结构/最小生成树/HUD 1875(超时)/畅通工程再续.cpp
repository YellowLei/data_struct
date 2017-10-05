#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
using namespace std;
struct edge
{
    int u,v;
    double w;
};//储存边
struct edge e[5005];
int T,n,m,ans;
double sum=0;
int f[105]={0},x[105],y[105],Count=0;
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
	if (f[v] == v)
	{
		return v;
	}
	else
	{
		//路径压缩
		f[v] = getf(f[v]);
		return f[v];
	}
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
int main ()
{
    scanf("%d",&T);
    while(T--)
    {

        memset(f,0,sizeof(f));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        Count=0,sum=0,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        m=1;
        int v=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                double distance=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                    e[m].u=i;
                    e[m].v=j;
                    e[m].w=distance;
                    m++;
                if(distance<=10&&distance>=1000)
                {
                    ans++;
                }
            }
        }
        quicksort(1,m);
        for(int i=1;i<=n;i++)
        {
            f[i]=i;
        }
        for (int i = 1; i <= m; i++)//枚举每一条边
        {
            if (merge(e[i].u, e[i].v))//判断是否联通，为联通就选择这条边
            {
                Count++;
                sum = sum + e[i].w;
            }
            if (Count == n - 1)
                break;
        }
        if(ans==n-1)
            printf("%.1lf\n", (sum*100));
        else printf("oh!\n");
    }
	return 0;
}
