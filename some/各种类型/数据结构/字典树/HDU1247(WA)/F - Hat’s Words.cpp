#include <stdio.h>
#include <iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
#define  MAX    26
const int maxn=50000;
typedef struct TrieNode
{
	bool flag;  //存储其是否是一个单词
	struct TrieNode *next[MAX]; //该节点的后续节点
} TrieNode;

TrieNode Memory[1000000]; //先分配好内存。 malloc 较为费时
int allocp = 0;

//初始化一个节点。nCount计数为1， next都为null
TrieNode * createTrieNode()
{
	TrieNode * tmp = &Memory[allocp++];
	tmp->flag=false;
	for (int i = 0; i < MAX; i++)
		tmp->next[i] = NULL;
	return tmp;
}

void insertTrie(TrieNode * pRoot, char * str)
{
    if(pRoot==NULL || *str=='\0')
        return;
	TrieNode * tmp =pRoot;
	int i = 0, id;
	//一个一个的插入字符
	while (str[i])
	{
		id = str[i] - 'a'; //当前字符 应该插入的位置
		if (tmp->next[id]==NULL)
		{
			tmp->next[id] = createTrieNode();
		}
		tmp = tmp->next[id];
		i++; //移到下一个字符
	}
	tmp->flag=true;
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
			return false;
		i++;
	}
	//return tmp->flag;
	return (tmp!=NULL&&tmp->flag==true); //返回其是否是单词
}
//释放空间
void dealTrie(TrieNode* T)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(T->next[i]!=NULL)
            dealTrie(T->next[i]);
    }
    free(T);
}
char s[maxn][100];
char head[100],last[100];
int main()
{
    TrieNode *root=createTrieNode();
    int n=0;
    for(int i=0;i<maxn;i++)
    {
        gets(s[i]);
//        if(s[i][0]=='\0')
//            break;
        insertTrie(root,s[i]);
        n++;
    }
    for(int i=0;i<n;i++)
    {
        int len=strlen(s[i]);
  //      printf("%d\n",i);
        for(int j=0;j<len-1;j++)
        {
            memset(head,0,sizeof(head));
            memset(last,0,sizeof(last));
            for(int u=0;u<=j;u++)
                head[u]=s[i][u];
//printf("head is %s\n",head);
            for(int u=j+1;u<len;u++)
                last[u-j-1]=s[i][u];
//printf("last is %s\n",last);
            if(searchTrie(root,head)&&searchTrie(root,last))
            {
                printf("%s\n",s[i]);
                break;
            }
        }
    }
    dealTrie(root);
    return 0;
}
//网上找的AC的代码
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <string>
//using namespace std;
//const int maxn = 26;
//struct Trie//结点声明
//{
//    struct Trie *next[maxn];//孩子分支
//    bool isStr;//标记是否构成单词
//};
//
//void Insert(Trie *root,const char *s)//将单词s插入Trie树
//{
//    if(root==NULL || *s=='\0')
//        return;
//    //int i;
//    Trie *p = root;
//    while(*s != '\0')
//    {
//        if(p->next[*s-'a'] == NULL) //如果不存在，则建立结点
//        {
//            Trie *tmp = (Trie*)malloc(sizeof(Trie));
//            for(int i=0; i<maxn; i++)
//                tmp->next[i] = NULL;
//            tmp->isStr = false;
//            p->next[*s-'a'] = tmp;
//            p = p->next[*s-'a'];
//        }
//        else
//            p = p->next[*s-'a'];
//        s++;
//    }
//    p->isStr = true;//单词结束的地方标记此处可以构成一个单词
//}
//
//int Find(Trie *root, const char *s)
//{
//    Trie *p = root;
//    while(p!=NULL && *s!='\0')
//    {
//        p = p->next[*s-'a'];
//        s++;
//    }
//    return (p!=NULL && p->isStr==true);//在单词结束处的标记为true时，单词才存在
//}
//
//void Del(Trie *root)//释放整个Trie树的空间
//{
//    for(int i=0; i<maxn; i++)
//    {
//        if(root->next[i] != NULL)
//            Del(root->next[i]);
//    }
//    free(root);
//}
//char s[50000][100];
//char str[100];
//int main()
//{
//    int m,n; //n为建立Trie树输入的单词数，m为要查找的单词数
//    Trie *root = (Trie *)malloc(sizeof(Trie));
//    for(int i=0; i<maxn; i++)
//        root->next[i] = NULL;
//    root->isStr = false;
//    int cnt = 0;
//    while(scanf("%s",str) != EOF)
//    {
//        strcpy(s[cnt++],str);
//        Insert(root, str);
//    }
//    for(int i=0; i<cnt; i++)
//    {
//        for(int j=1; j<strlen(s[i]); j++)
//        {
//            char tmp1[100] = {'\0'};
//            char tmp2[100] = {'\0'};
//            /*strncpy函数是指(char s1,char s2, int len)三个参数，将s2的len个数
//            复制给s1,但是最后要加'\0'要不然就会。。。。*/
//            strncpy(tmp1, s[i], j);
//            strncpy(tmp2, s[i]+j, strlen(s[i])-j);
//            if(Find(root, tmp1) && Find(root, tmp2))
//            {
//                printf("%s\n",s[i]);
//                break;
//            }
//        }
//    }
//    Del(root);
//    return 0;
//}
