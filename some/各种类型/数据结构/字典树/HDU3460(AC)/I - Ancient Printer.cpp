#include <stdio.h>
#include <iostream>
#include<cstring>
using namespace std;
#define  MAX    26
int sum;
typedef struct TrieNode
{
	int v;  // 该节点前缀 出现的次数
	struct TrieNode *next[MAX]; //该节点的后续节点
} TrieNode;

TrieNode Memory[1000000]; //先分配好内存。 malloc 较为费时
int allocp = 0;

//初始化一个节点。nCount计数为1， next都为null
TrieNode * createTrieNode()
{
	TrieNode * tmp = &Memory[allocp++];
	tmp->v = 1;
	for (int i = 0; i < MAX; i++)
		tmp->next[i] = NULL;
	return tmp;
}

int  insertTrie(TrieNode * pRoot, char * str)
{
	TrieNode * tmp =pRoot;
	int i = 0, id;
	int newNode=0;
	//一个一个的插入字符
	while (str[i])
	{
		id = str[i] - 'a'; //当前字符 应该插入的位置
		if (tmp->next[id])
		{
			tmp->next[id]->v++;
		}
		else
		{
			tmp->next[id] = createTrieNode();
			sum++;                              //创建一个新结点sum++
			newNode++;                          //创建一个新结点等会要delete的newNode++

		}

		tmp = tmp->next[id];
		i++; //移到下一个字符
	}
	sum++;                      //一个队名insert完后要打印sum++
	return newNode;
}
int main()
{
    int n,a[10005],longest=0;
    while(scanf("%d",&n)!=EOF)
    {
        sum=longest=0;
        memset(a,0,sizeof(a));
        TrieNode * root=createTrieNode();
        for(int i=0;i<n;i++)
        {
            char s[55];
            scanf("%s",s);
            if(longest<strlen(s))
                longest=strlen(s);
            a[i]=insertTrie(root,s);
        }
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        printf("%d\n",sum-longest);
    }
    return 0;
}
