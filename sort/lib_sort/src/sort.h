#ifndef SORT_H
#define SORT_H

#include <string.h>
#include <math.h>

const int MAX = 9999999;

//快速排序
template<typename T>
void qsort(T a[], int low, int high)
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
//插入排序
void insertsort(int* arr, int len);

void insertsort2(int arr[], int len);

//交换排序
void swapsort(int arr[], int len);

//选择排序
void selectsort(int arr[],int len);	

//基数排序
void radixsort(int arr[], int len);

//桶排序
void bucketSort(int *arr, int len);

//归并排序
void mergesort(int *arr, int start, int last, int *result);

//辅助函数

//归并算法
void merge(int *arr, int start, int last)
{
	int *result = new int[last-start+1];
	int mid = (start+last)/2;

	int i = start;
	int j = mid + 1;	//避免重复比较mid
	int k = 0;

	//开始归并
	while(i <= mid && j <= last)	
	{
		if(arr[i] <= arr[j])
			result[k++] = arr[i++];
		else
			result[k++] = arr[j++];
	}

	while(i <= mid)
	{
		result[k++] = arr[i++];
	}

	while(j <= last)
	{
		result[k++] = arr[j++];
	}

	//将归并后的数组的值逐一赋给数组arr[start,end]
	for(i = 0; i < k; i++)
	{
		arr[start+i] = result[i];	//从arr[start+i]开始赋值
	}

	delete[]result;
}

//寻找数组里面最大数的位数
int getmaxbit(int arr[], int len)
{
	int cout = 1;	//保存最大的位数
	int temp = 10;
	for(int i = 0; i < len; i++)
	{
		if(arr[i] >= temp)
		{
			temp *= 10;
			cout++;
		}
	}
	return cout;
}

#endif