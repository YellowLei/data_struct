#include "sort.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[] = {1,24,35,12,634,21,5};
	int result[10];
	mergesort(arr,0,6,result);
	for(int i = 0;i < 7;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
