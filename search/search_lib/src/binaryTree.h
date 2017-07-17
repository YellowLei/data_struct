#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdlib.h>
//二叉树结构体
typedef struct node
{
	int key;
	int index;	//在原始数组中的坐标
	struct node *left;
	struct node *right;
	struct node *parent;
}Node, *PNode;

class binaryTree
{
public:
	//创建一棵二叉树
	void create(PNode *root, int *arr, int len);

	//插入节点
	//插入的话，可能要改变根结点的地址，所以传的是二级指针
	void insert(PNode *root, int key, int index);

	//查找节点，没有返回null
	PNode binaryTreeSearch(PNode root, int key);

	//查找最大节点
	PNode searchMax(PNode root);

	//查找最小节点
	PNode searchMin(PNode root);

	//查找某个结点的前驱
	PNode searchPredecessor(PNode p);

	//查找某个结点的后继
	PNode searchSuccessor(PNode p);

	//根据关键字删除某个结点,删除成功返回1,否则返回0
	//如果把根结点删掉，那么要改变根结点的地址，所以传二级指针
	bool deleteNode(PNode* root,int key);
};

#endif