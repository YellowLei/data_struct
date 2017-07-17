#include "sort.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[10] = {13,5,1,89,3,57,0,4,6,19};
	float a[10] = {13.6,5.4,1.6,89.0,3.3,57,0,4,6,19};
	
	qsort<int>(arr,0,9);

	for(int i = 0;i <= 9;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}