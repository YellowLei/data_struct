#include "AVLTree.h"
#include <stdio.h>

//左左旋转
pavlnode AVLTree::LLrotation(pavlnode root)
{
	pavlnode p;
	p = root->left;
	root->left = p->right;
	p->right = root;
	return p;
}

//右右旋转
pavlnode AVLTree::RRrotation(pavlnode root)
{
	pavlnode p;
	p = root->right;
	root->right = p->left;
	p->left = root;
	return p;
}

//右左旋转
pavlnode AVLTree::RLrotation(pavlnode root)
{
	root = RRrotation(root);
	return LLrotation(root);
}

//左右旋转
pavlnode AVLTree::LRrotation(pavlnode root)
{
	root = LLrotation(root);
	return RRrotation(root);
}

//平衡函数
pavlnode AVLTree::balance(pavlnode root)
{
	printf("in balance\n");
	if(root->balanceFactor > 1)	//左边长
	{
		if(root->left->balanceFactor > 0) //左边的孩子还是左边长
			root = LLrotation(root);
		else
			root = LRrotation(root);
	}
	else
	{
		if(root->balanceFactor < -1)
		{
			if(root->right->balanceFactor > 0)
				root = RLrotation(root);
			else
				root = RLrotation(root);
		}
	}
	return root;
}

//构造函数，数组构造
AVLTree::AVLTree(const int *arr, int len)
{
	avlroot = NULL;
	for(int i = 0; i < len; i++)
	{
		insert(&avlroot, arr[i], i);
		printf("charujiedian\n");
	}
}

//插入
pavlnode AVLTree::insert(pavlnode *root, const int key, const int index)
{
	pavlnode p = new avlnode(key, index);
	if(*root == NULL)
	{
		*root = p;
		return *root;
	}

	//插入到当前节点的左子树
	if( (*root)->left == NULL && key < (*root)->key)
	{
		(*root)->left = p;
		p->parent = (*root);
		changeBalance(p);
		return balance(*root);
	}

	//插入到当前节点的右子树
	if((*root)->right == NULL && key > (*root)->key)
	{
		(*root)->right = p;
		p->parent = (*root);
		changeBalance(p);
		return balance(*root);
	}

	//左右子树都不为空，递归
	if(key > (*root)->key)
		insert(&(*root)->right, key, index);
	else if(key < (*root)->key)
		insert(&(*root)->left, key, index);
	else return balance(*root);	//key与树中某一节点相同时也可以跳出递归
}

//改变balanceFactor
void AVLTree::changeBalance(pavlnode p)
{
	while(p->parent)
	{
		if(p == p->parent->right)
			p->parent->balanceFactor -=1;
		else p->parent->balanceFactor +=1;
	}
}

//删除
bool AVLTree::deleteNode(pavlnode *root, const int key)
{
	if((*root) == NULL)
	{
		cout << "Delete error , tree is null" <<endl;
		return false;
	}
	//找到要删除的节点
	pavlnode p = search(avlroot,key);
	if (!p)
    {
        cout << "Delete error , key not find" <<endl;
        return false;
    }

    //1.删除的是叶子节点
    if(p->right == NULL && p->left == NULL)
	{
		if(p->parent == NULL)
		{
			*root = NULL;
		}
		else
		{
			if(p->parent->right = p)
				p->parent->right == NULL;
			else 
				p->parent->left == NULL;
		}
		delete p;
    }
   	//2.删除的节点只有左孩子，没有右孩子
    else if(p->right == NULL && p->left != NULL)
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
   	//3.删除的节点只有右孩子，没有左孩子
    else if(p->right != NULL && p->left == NULL)
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
    //4.删除的节点有左右孩子
    else
    {
		//用后继的值替换该节点，后继直接删除，后继是没有孩子的
		pavlnode temp = searchSuccessor(p);
		int t = temp->key;
		deleteNode(root,temp->key);
		p->key = t;
    }
}

//查询
pavlnode AVLTree::search(const pavlnode root, const int key)
{
	if(root == NULL)
		return NULL;
	if(key == root->key)
		return root;
	else if(key < root->key)
		return search(root->left, key);
	else
		return search(root->right, key);
}

//查找某个结点的后继
pavlnode AVLTree::searchSuccessor(pavlnode p)
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
//查找最小关键字
pavlnode AVLTree::searchMin(pavlnode root)
{
	if(root == NULL)
		return NULL;
	if(root->left == NULL)
		return root;
	else return searchMin(root->left);
}
//中序遍历
void AVLTree::InorderTraversal(pavlnode root)
{
	if(root == NULL)
	{
		cout << "Traversal error , tree is null" <<endl;
		return ;
	}
	InorderTraversal(root->left);
	cout<<avlroot->key<<endl;
	InorderTraversal(root->right);
}
