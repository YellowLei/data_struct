#include "binaryTree.h"

//创建一棵二叉树
void binaryTree::create(PNode *root, int *arr, int len)
{
	for(int i = 0;i < len; i++)
		insert(root,arr[i],i);
}

//往二叉树中插入节点
void binaryTree::insert(PNode *root, int key, int index)
{
	//初始化一个节点
	PNode p = new Node;	//new的是一个
	p->key = key;
	p->left = p->right = p->parent = NULL;

	//如果是一个空树
	if(*root == NULL)
	{
		*root = p;
		return ;
	}	

	//插入到当前节点的左子树
	if( (*root)->left == NULL && key < (*root)->key)
	{
		(*root)->left = p;
		p->parent = (*root);
		return;
	}

	//插入到当前节点的右子树
	if((*root)->right == NULL && key > (*root)->key)
	{
		(*root)->right = p;
		p->parent = (*root);
		return ;
	}

	//左右子树都不为空，递归
	if(key > (*root)->key)
		insert(&(*root)->right, key, index);
	else if(key < (*root)->key)
		insert(&(*root)->left, key, index);
	else return;	//key与树中某一节点相同时也可以跳出递归
}

//二叉查找
PNode binaryTree::binaryTreeSearch(PNode root, int key)
{
	if(root == NULL)
		return NULL;

	if(key > root->key)
		return binaryTreeSearch(root->right, key);
	else if(key < root->key)
		return binaryTreeSearch(root->left, key);
	else
		return root;
}

//查找最大关键字
PNode binaryTree::searchMax(PNode root)
{
	if(root == NULL)
		return NULL;
	if(root->right == NULL)
		return root;
	else return searchMax(root->right);
}

//查找最小关键字
PNode binaryTree::searchMin(PNode root)
{
	if(root == NULL)
		return NULL;
	if(root->left == NULL)
		return root;
	else return searchMin(root->left);
}

//查找某个结点的前驱
PNode binaryTree::searchPredecessor(PNode p)
{
	if(p == NULL)
		return NULL;
	//如果有左子树，则前驱为左子树最大值
	if(p->left != NULL)
		return searchMax(p->left);
	else	//无左子树，遍历查找某个右子树中p是最小的，该右子树的root就是前驱
	{
		if(p->parent == NULL)
			return NULL;
		while(p)
		{
			if(p->parent->right == p)
				break;
			p = p->parent;
		}
		return p->parent;
	}
}

//查找某个结点的后继
PNode binaryTree::searchSuccessor(PNode p)
{
	if(p == NULL)
		return NULL;
	//如果有右子树，则后继为又子树最小值
	if(p->right != NULL)
		return searchMin(p->right);
	else	//无又子树，遍历查找某个左子树中p是最大的，该左子树的root就是后继
	{
		if(p->parent == NULL)
			return NULL;
		while(p)
		{
			if(p->parent->left == p)
				break;
			p = p->parent;
		}
		return p->parent;
	}
}

//根据关键字删除某个结点,删除成功返回1,否则返回0
//如果把根结点删掉，那么要改变根结点的地址，所以传二级指针
bool binaryTree::deleteNode(PNode* root,int key)
{
	//首先找到需要删除的节点
	PNode  p = binaryTreeSearch(*root,key);
	if(p == NULL)
		return false;

	//1.删除节点没有左右孩子，直接删除
	if(p->left == NULL && p->right == NULL)
	{
		//删除的是根节点，root需要改变
		if(p->parent == NULL)
			(*root) = NULL;
		else
		{
			if(p->parent->right == p)	//删除的是父节点的右孩子
				p->parent->right = NULL;
			else
				p->parent->left = NULL;
		}
		delete p;
	}
	//2.删除的节点只有右孩子
	else if(p->left == NULL && p->right != NULL)
	{
		p->right->parent=p->parent;
		//删除的是根节点，root需要改变
		if(p->parent == NULL)
			(*root) = p->right;
		if(p->parent->right == p)	//删除的是父节点的右孩子
			p->parent->right = p->right;
		else
			p->parent->left = p->right;
		delete p;
	}
	//3.删除的节点只有左孩子
	else if(p->left != NULL && p->right == NULL)
	{
		p->left->parent=p->parent;
		//删除的是根节点，root需要改变
		if(p->parent == NULL)
			(*root) = p->left;
		if(p->parent->right == p)	//删除的是父节点的右孩子
			p->parent->right = p->left;
		else
			p->parent->left = p->left;
		delete p;
	}
	//4.删除的节点有左右孩子
	else if(p->left != NULL && p->right != NULL)
	{
		//用后继的值替换该节点，后继直接删除，后继是没有孩子的
		PNode temp = searchSuccessor(p);
		int t = temp->key;
		deleteNode(root,temp->key);
		p->key = t;
	}

	return true;
}

