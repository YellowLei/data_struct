#ifndef SEARCH_H
#define SEARCH_H

#include "sort.h"
#include "math.h"
#include "binaryTree.h"
#include "AVLTree.h"

//分块查找索引表的数据结构
struct indextable
{
	int value; //快中最大关键字
	int index; //块中最大字的下标
};

class search
{
public:
	//顺序查找
	int SequenceSearch(int *arr, const int key, int len);

	//折半查找（二分查找）
	int BinarySearch(int *arr, const int key, int first, int last );

	//分块查找
	int BlockSearch(int *arr, const int key, int len);

	//二叉排序树查找 

	//平衡二叉排序树查找

	//B—树查找法和B+树查找法
	//键树查找

	//哈希查找法
};
#endif