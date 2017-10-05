#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
using namespace std;
const int Max=26;
typedef struct TrieNode
{
    int v;
    TrieNode *next[Max];
};

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
void insertTrie(TrieNode * root,char *str)
{
    TrieNode *p=root;
	int i = 0, k;
	//一个一个的插入字符
	while (str[i])
	{
		k = str[i] - 'a'; //当前字符 应该插入的位置
		if (p->next[k])  //该字符存在
		{
			p->next[k]->v++;
		}
		else
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
int main ()
{
    char word[11];
    TrieNode *Root = createTrieNode();
    while(gets(word)&&word[0]!='\0')
    {
        insertTrie(Root,word);
    }
    while(gets(word)&&word[0]!='\0')
    {
        int m=searchTrie(Root,word);
        printf("%d\n",m);
    }
}
