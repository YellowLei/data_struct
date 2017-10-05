#include<stdio.h>
#include<math.h>
#include<string.h>
float getMax(float a,float b)
{
    return a>b?a:b;
}
int main()
{
	int T, i, j, n, value[110];
	float m, pro[110], f[10010];
	scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		int sum = 0;
		scanf("%f%d",&m,&n);
		m = 1 - m;//成功逃走的概率
		for(i = 1; i <= n; i++)
		{
			scanf("%d%f",&value[i],&pro[i]);
			sum += value[i];//算出银行总钱数
			pro[i] = (1 - pro[i]);
		}
		f[0] = 1;//未抢劫一分钱那么逃走的概率就为1
		for(i = 1; i <= n; i++)
		{
			for(j = sum; j >= value[i]; j--)
			{
				f[j] = getMax(f[j],f[j - value[i]] * pro[i]);//这里的每次成功的概率需要进行乘法运算，因为是两次成功的概率所以是乘法
			}
		}
		for(i = sum; i >= 0; i--)
		{
			if(f[i] >= m)
			{
				printf("%d\n",i);
				break;//找出可以成功逃走并且逃走概率不超过警戒值
			}
		}
	}
	return 0;
}
