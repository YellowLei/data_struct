#include "search.h"

//顺序查找
int SequenceSearch(int *arr, int key, int len)
{
	for(int i = 0; i < len; i++)
	{
		if(arr[i] == key)
			return i;
	}

	return -1;
}