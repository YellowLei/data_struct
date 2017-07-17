#include "search.h"


//顺序查找
int search::SequenceSearch(int *arr, const int key, int len)
{
	for(int i = 0; i < len; i++)
	{
		if(arr[i] == key)
			return i;
	}

	return -1;
}

//二分查找
int search::BinarySearch(int *arr, const int key, int first, int last)
{
	if(first > last)
		return -1;

	//递归
	int mid = (first + last) / 2;
	
	if(key == arr[mid])
		return mid;
	else if(key < arr[mid])
		return BinarySearch(arr, key, first, mid - 1);
	else return BinarySearch(arr, key, mid + 1, last);

	//非递归
	// while(first <= last)
	// {
	// 	int mid = (first + last) / 2;
	// 	if(key == arr[mid])
	// 		return mid;
	// 	else if(key < arr[mid])
	// 		last = mid - 1;
	// 	else first = mid + 1;
	// }

	return -1;
}

//分块查找
int search::BlockSearch(int *arr, const int key, int len)
{
	//确定分块数量	
	int block_len = sqrt(len);	//当每块有sqrt(len)个元素时，查找效率最好
	int b = len%block_len == 0 ? 0 : 1;
	int block_num = len / block_len + b;	//分块的数量

	//new一个　索引表
	struct indextable *table = new indextable[block_num];
	int max, temp_index;

	//建立索引表
	for(int i = 0; i < block_num; i++)
	{
		max = arr[i*block_len];
		for(int j = i * block_len; j < len && (j - i * block_len) < block_len; j++)
		{
			if(max < arr[j])
			{
				max = arr[j];
				temp_index = j;
			}
		}

		table[i].value = max;
		table[i].index = temp_index;
	}

	//二分查找目标所在块
	int first = 0;
	int last = block_num - 1;
	while(first <= last)
	{
		int mid = (first + last) / 2;
		if(table[mid].value == key)
		{
		}
	}


	//在块内用顺序查找目标
}