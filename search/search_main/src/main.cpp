#include <iostream>
#include <stdio.h>
#include "search.h"

using namespace std;

int main()
{
	int arr[10] = {1,5,3,2,6,7,9,0,8,4};
	cout<<"3的位置为:%d \n"<<SequenceSearch(arr,3,10)<<endl;
	//printf("3的位置为:%d \n",SequenceSearch(arr,3,10)); //位置从0开始算
	return 0;

}