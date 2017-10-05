#include <stdio.h>
#include <iostream>
#include<cstring>
using namespace std;
#define  MAX    26

typedef struct TrieNode
{
	char Eng[11];   //存储英语
	struct TrieNode *next[MAX]; //该节点的后续节点
} TrieNode;

TrieNode Memory[1000000]; //先分配好内存。 malloc 较为费时
int allocp = 0;

//初始化一个节点。nCount计数为1， next都为null
TrieNode * createTrieNode()
{
	TrieNode * tmp = &Memory[allocp++];
	for(int i=0;i<11;i++)
        tmp->Eng[i]='\0';
	for(int i = 0; i < MAX; i++)
		tmp->next[i] = NULL;
	return tmp;
}

void insertTrie(TrieNode * pRoot, char * Eng, char * str)
{
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
    strcpy(tmp->Eng,Eng);
}

void searchTrie(TrieNode * root, char * str)
{
	TrieNode * tmp = root;
	int i = 0, id;
	while (str[i])
	{
		id = str[i] - 'a';
		if (tmp->next[id]==NULL)
        {
            printf("%s",str);
			return;
        }

        tmp=tmp->next[id];
		i++;
	}
	if(tmp->Eng==NULL)
        printf("%s",str);
    else
        printf("%s",tmp->Eng);
}
int main()
{
        char e[11],m[11];
        TrieNode * root=createTrieNode();
        scanf("%s",e);
        while(~scanf("%s",e))
        {
            if(strcmp(e,"END")==0)
                break;
            scanf("%s",m);
            insertTrie(root,e,m);
        }
        scanf("%s",e);
        getchar();
        char s[3005];
        while(gets(s))
        {
            if(strcmp(s,"END")==0)
                break;
            char t[3001]={0};
            int j=0;
            for(int i=0;s[i];i++)
            {
                if('a'<=s[i]&&s[i]<='z')
                {
                    t[j++]=s[i];
                }
                else
                {
                    t[j]='\0';
                    if(t[0]!='\0')
                    {
                        searchTrie(root,t);
                        t[0]='\0',j=0;
                    }
                    printf("%c",s[i]);
                }
            }
            printf("\n");
        }
        return 0;
}
