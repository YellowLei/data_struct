#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
using namespace std;
const int Max=26;
typedef struct TrieNode
{
    int v;      //记录以这个单词为字串的有多少个商品
    int flag;   //标记是否加过，每个商品的flag都不同
    TrieNode *next[Max];
};

//初始化一个结点
TrieNode *createTrieNode()
{
    TrieNode *tmp=(TrieNode *)malloc(sizeof(TrieNode));
    tmp->v=0;           //初始化为0，表示最开始没商品
    tmp->flag=-1;       //做记号，防止出现，abab和ab这种会存入两次，当flag不是当前商品时v才会加
    for(int i=0;i<Max;i++)
        tmp->next[i]=NULL;
    return tmp;
}
//插入节点
void insertTrie(TrieNode * root,char *str,int flag)
{
    TrieNode *p=root;
	int i = 0, k;
	//一个一个的插入字符
	while (str[i])
	{
		k = str[i] - 'a'; //当前字符 应该插入的位置
		if (p->next[k]==NULL)  //该字符不存在
		{
			p->next[k] = createTrieNode();
		}
		p = p->next[k];
        if(p->flag!=flag)//如果当前结点的商品flag不等于要插入商品的flag，则计数器v++，并且重新置flag的值
         {
            p->flag=flag;
            p->v++;
        }
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
	int sum;
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
int main()
{
    int n,m;
    char name[21];
    TrieNode * root=createTrieNode();
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",name);
        //关键
        for(int i=0;i<strlen(name);i++)     //将字符串X=X1X2...Xn的分别以X1,X2...Xn开头的后缀字符串插入到Trie树中
            insertTrie(root,name+i,n);      //既把后缀加到字符串里(name+i)
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s",name);
        printf("%d\n",searchTrie(root,name));
    }
}
