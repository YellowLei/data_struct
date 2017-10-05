//Trie的核心思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。
//它有3个基本性质：
//
//1.根节点不包含字符，除根节点外每一个节点都只包含一个字符。
//2.从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
//3.每个节点的所有子节点包含的字符都不相同。



//trie的数据结构
const int Max=26;
typedef struct TrieNode
{
    int v;                  //记录到当前结点有几个字符串
    TrieNode *next[Max];    //指向其子树
};

//next是表示每层有多少种类的数，如果只是小写字母，则26即可，若改为大小写字母，则是52，
//若再加上数字，则是62了，这里根据题意来确定。
//v可以表示一个字典树到此有多少相同前缀的数目，这里根据需要应当学会自由变化

//Trie的查找（最主要的操作）：
//(1) 每次从根结点开始一次搜索；
//(2) 取得要查找关键词的第一个字母，并根据该字母选择对应的子树并转到该子树继续进行检索； 　　(3) 在相应的子树上，取得要查找关键词的第二个字母,并进一步选择对应的子树进行检索。 　　
//(4) 迭代过程…… 　　
//(5) 在某个结点处，关键词的所有字母已被取出，则读取附在该结点上的信息，即完成查找。


//初始化一个结点
TrieNode *createTrieNode()
{
    TrieNode *tmp=(TrieNode *)malloc(sizeof(TrieNode));
    tmp->v=1;
    for(int i=0;i<Max;i++)
        tmp->next[i]=NULL;
    return tmp;
}
//插入节点
void insertTrie(TrieNode * * root,char *str)
{
    TrieNode *p=*root;
	int i = 0, k;
	//一个一个的插入字符
	while (str[i])
	{
		k = str[i] - 'a'; //当前字符 应该插入的位置
		if (p->next[k])  //该字符存在
		{
			p->next[k]->v++;
		}
		else            //该字符不存在，创建一个
		{
			p->next[k] = createTrieNode();
		}

		p = p->next[k];
		i++; //移到下一个字符
	}
}
//寻找字符串
int searchTrie(TrieNode * root, char *str)
{
	if (root == NULL)
		return 0;
	TrieNode * tmp = root;
	int i = 0, k;
	while (str[i])
	{
		k = str[i] - 'a';
		if (tmp->next[k])
		{
			tmp = tmp->next[k];
		}
		else
			return 0;
		i++;
	}
	return tmp->v; //返回最后的那个字符  所在节点的 v
}


//释放空间
void dealTrie(TrieNode* T)
{
    int i;
    for(i=0;i<Max;i++)
    {
        if(T->next[i]!=NULL)
            dealTrie(T->next[i]);
    }
    free(T);
}

//例子
//copyright: www.acmerblog.com
#include <stdio.h>
#include <iostream>
using namespace std;
#define  MAX    26

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

void insertTrie(TrieNode * pRoot, char * str)
{
	TrieNode * tmp = pRoot;
	int i = 0, id;
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
		}

		tmp = tmp->next[id];
		i++; //移到下一个字符
	}

}

int searchTrie(TrieNode * root, char * str)
{
	if (root == NULL)
		return 0;
	TrieNode * tmp = root;
	int i = 0, id;
	while (str[i])
	{
		id = str[i] - 'a';
		if (tmp->next[id])
		{
			tmp = tmp->next[id];
		}
		else
			return 0;
		i++;
	}
	return tmp->v; //返回最后的那个字符  所在节点的 v
}

int main(void)
{
	char s[11];
	TrieNode *Root = createTrieNode();
	while (gets(s) && s[0] != '\0') //读入0 结束
	{
		insertTrie(Root, s);
	}

	while (gets(s)&& s[0] != '\0') //查询输入的字符串
	{
		printf("%d\n", searchTrie(Root, s));
	}

	return 0;
}

