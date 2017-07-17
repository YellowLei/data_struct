#include <iostream>
#include "search.h"
#include "sort.h"

#include <stdio.h>

using namespace std;

int main()
{
	int arr[10] = {1,5,3,2,6,7,9,0,8,4};
	AVLTree avl(arr,10);
	avl.insert(&(avl.avlroot),10,11);

	avl.InorderTraversal(avl.avlroot);

	//search s;
	//int arr[10] = {1,5,3,2,6,7,9,0,8,4};

	// qsort(arr,0,9);	//二分查找前要先排序
	// for(int i = 0; i < 10;i++)
	// 	cout<<arr[i]<<endl;
	//cout<<"3的位置为:"<<s.BinarySearch(arr,3,0,9)<<endl;

	// int i;
	// binaryTree tree;
 //    PNode root=NULL;
 //    int nodeArray[11]={15,6,18,3,7,17,20,2,4,13,9};
 //    tree.create(&root,nodeArray,11);
    
 //    for(i=0;i<2;i++)
 //        tree.deleteNode(&root,nodeArray[i]);

 //    printf("%d\n",tree.searchPredecessor(root)->key);
 //    printf("%d\n",tree.searchSuccessor(root)->key);
 //    printf("%d\n",tree.searchMin(root)->key);
 //    printf("%d\n",tree.searchMax(root)->key);
 //    printf("%d\n",tree.binaryTreeSearch(root,13)->key);

	return 0;
}