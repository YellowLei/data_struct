#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct AVLNode
{
	int key;
	int index;	//在原始数组中的坐标
	int balanceFactor; //节点平衡因子
	struct AVLNode *left;
	struct AVLNode *right;
	struct AVLNode *parent;

	AVLNode():
		key(0),index(0),balanceFactor(0),left(NULL),right(NULL),parent(NULL){}
	AVLNode(int _key, int _index):
		key(_key),index(_index),balanceFactor(0),left(NULL),right(NULL),parent(NULL){}
}avlnode,*pavlnode;


class AVLTree
{
private:

	//两种单旋转
	pavlnode LLrotation(pavlnode root); //左左旋转
	pavlnode RRrotation(pavlnode root); //右右旋转

	//两种双旋转
	pavlnode RLrotation(pavlnode root); //右左旋转
	pavlnode LRrotation(pavlnode root); //左右旋转

	//平衡函数，里面包含四种旋转
	pavlnode balance(pavlnode root);

public:
	pavlnode avlroot;
	AVLTree(){ avlroot = NULL; }//默认构造函数

    AVLTree(const int *arr, int len);//构造函数，数组构造

	//改变balanceFactor
	void changeBalance(pavlnode p);

	//插入
	pavlnode insert(pavlnode *root, const int key, const int i);

	//删除
	bool deleteNode(pavlnode *root, const int key);

	//查询
	pavlnode search(const pavlnode root, const int key);

	//中序遍历
	void InorderTraversal(pavlnode root);

	//查找最小关键字
	pavlnode searchMin(pavlnode root);

	//查找某个结点的后继
	pavlnode searchSuccessor(pavlnode p);
};


#endif
