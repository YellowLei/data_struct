#include "sort.h"

//快排
/*
template<typename T> 
void qsort(int a[], int low, int high)
{
	while(low >= high)
	{
		return;
	}

	int first = low;
	int last = high;
	int key = a[first];

	while(first < last)
	{
		while(first < last && a[last] >= key)
		{
			last--;
		}

		a[first] = a[last];

		while(first < last && a[first] <= key)
		{
			first++;
		}

		a[last] = a[first];
	}

	a[first] = key;

	qsort(a,low,first-1);
	qsort(a,first+1,high);
}
*/

//插入排序
void insertsort(int *arr, int len)
{
	int i,j;
	int temp;
	for(i = 1;i < len;i++)
	{
		temp = *(arr + i);
		for(j = i; j>0 && *(arr+j-1) > temp; j--)
		{
			*(arr+j) = *(arr+j-1);
		}
		*(arr+j) = temp;
	}
}

void insertsort2(int arr[], int len)
{
	int i,j;
	int temp;
	for(i = 1; i < len; i++)
	{
		temp = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j--;
		}

		if(j != i-1)
		{
			arr[j+1] = temp;
		}
	}
}

//交换排序:把值较小的直接往前提
void swapsort(int arr[], int len)
{
	int temp;
	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1;j < len; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

//选择排序
void selectsort(int arr[], int len)
{
	int minflag,temp;
	for(int i = 1; i < len-1; i++)
	{
		minflag = i;
		for(int j = i+1; j < len;j++)
		{
			if(arr[i] > arr[j])
				minflag = j;
		}
		if(minflag != i)
		{
			temp = arr[minflag];
			arr[minflag] = arr[i];
			arr[i] = temp;
		}
	}
}

//桶排序
void bucketSort(int *arr, int len)
{
	int bucketlen = len + 1;

	//建立一组桶，10*20的数组，浪费空间，排序的数量不多
	//用buckets[i][0]存储放在该桶中数的个数，所以bucketlen要为len+1
	int buckets[10][bucketlen] = {0};	

	//使用辅助函数得到数组中最大数的位数，就是用桶的循环次数
	int loopTimes = getmaxbit(arr,len);

	//从个位开始逐位开始桶循环
	for(int loop = 1; loop <= loopTimes; loop++)
	{
		//基数，个位是1，十位是10....
		int radix = (int)pow(10,loop-1);

		//开始一轮入桶
		for(int i = 0; i < len; i++)
		{
			//得到loop位的数字，1加入到桶1，依次...
			int row_index = (*(arr + i) / radix) % 10;
			
			//往桶里加
			int num = ++buckets[row_index][0];
			buckets[row_index][num] = *(arr + i);
		}

		//把数据按桶里的顺序写回原始数组
		for(int i = 0,n = 0; i < 10;i++)
		{
			for(int j = 1; j <= buckets[i][0]; j++)
			{
				*(arr+n) = buckets[i][j];
				n++;
			}
			buckets[i][0] = 0;	//清零
		}

	}
}

//基数排序c++
void radixsort(int *arr, int len)
{
	//获取循环数
	int loopTimes = getmaxbit(arr, len);

	//新开辟一个与arr相同长度的数组空间tmp
	int *tmp = new int[len];
	
	//开辟一个长度为10的计数器数组，保证所有桶放在一个数组tmp的位置
	int *count = new int[10]; 

	int radix = 1;
	int index;

	for(int loop = 1; loop <= loopTimes; loop++)
	{
		//每次循环计数器都要清零
		memset(count,0,sizeof(int)*10);

		//先计算每个桶需要多大，
		for(int i = 0; i < len; i++)
		{
			index = (arr[i] / radix) % 10;
			count[index]++;
		}

		//将tmp中的位置依次分配给每个桶
		for(int i = 1; i < 10; i++)
		{
			count[i] = count[i-1] + count[i];
		}

		//把arr数据放入tmp中
		for(int i = len-1; i >= 0; i--)
		{
			index = (arr[i] / radix) % 10;
			tmp[count[index]-1] = arr[i];
			count[index]--;
		}

		//把临时数组tmp中的数据再写回arr中
		for(int i = 0; i < len; i++)
		{
			arr[i] = tmp[i];
		}
		radix *= 10;
	}
	//释放新开辟的数组
	delete[]tmp;
    delete[]count;
}

//归并排序
void mergesort(int *arr, int start, int last, int *result)
{
	//普通过程
	// if(start < last)
	// {
	// 	int mid = (start + last) / 2;
	// 	mergesort(arr, start,mid, result);
	// 	mergesort(arr, mid+1,last, result);
	// 	merge(arr, start, last);
	// }
	//在数组长度较小时使用插入算法可以提高速度
	if((last - start) >= 50)	//在长度小于50时使用插入排序
	{
		int mid = (start + last) / 2;
		mergesort(arr, start,mid, result);
		mergesort(arr, mid+1,last, result);
		merge(arr, start, last);
	}
	else
		insertsort(arr, last-start+1);
}

