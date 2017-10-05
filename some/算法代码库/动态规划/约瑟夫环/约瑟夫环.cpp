
//解释http://blog.csdn.net/wuzhekai1985/article/details/6628491

//模拟全部过程,O(m*n)
#include<iostream>
using namespace std;
int main()
{
	int N;//人的总个数
	int M;//间隔多少个人

	cin>>N;
	cin>>M;

	bool *p=new bool[N+1];//[1……N]为true表示此人还活着
	for (int i=1; i <= N; i++)
		*(p+i)=true;

	int count=0;//统计自杀的人数

	for (int i=1, j=0; ;i++)//i用来表示循环，j用来计算是不是第N个人
	{
		if (*(p+i))//此人还活着
		{
			j++;
			if (j == M)
			{
				*(p+i)=false;
				j=0;
				count++;//统计自杀的人
			}
			if (count == N)
			{
				cout<<"最后自杀的人是："<<i<<endl;
				break;
			}
		}

		if(i == N)
			i=0;
	}

	delete []p;

	return 0;
}


//用数学的方法，O(n);
#include<iostream>
using namespace std;
int main()
{
	int N;//人的总个数
	int M;//间隔多少个人

	cin>>N;
	cin>>M;
	int result=0;//N=1情况
	for (int i=2; i<=N; i++)
	{
		result=(result+M)%i;
	}
	cout<<"最后自杀的人是："<<result+1<<endl;//result要加1
	return 0;
}
