#include <stdio.h>
#include <iostream>
#include<cstring >
using namespace std;
#define  MAX    10

typedef struct TrieNode
{
	char str[101];  //存字符串
	int v;          //存上述字符串出现的次数
	struct TrieNode *next[MAX]; //该节点的后续节点
} TrieNode;

TrieNode Memory[1000000]; //先分配好内存。 malloc 较为费时
int allocp = 0;

//初始化一个节点。nCount计数为1， next都为null
TrieNode * createTrieNode()
{
	TrieNode * tmp = &Memory[allocp++];
	tmp->v=0;
	for (int i = 0; i < MAX; i++)
        tmp->next[i] = NULL;
    for(int i=0;i<101;i++)
        tmp->str[i]='\0';
	return tmp;
}

void insertTrie(TrieNode * pRoot, char * str,char * s,int times)
{
	TrieNode * tmp =pRoot;
	int i = 0, id;
	//一个一个的插入字符
	while (str[i])
	{
		id = str[i] - '0'; //当前字符 应该插入的位置
		if (tmp->next[id]==NULL)
		{
			tmp->next[id] = createTrieNode();
			for(int j=0;j<=i;j++)
                tmp->next[id]->str[j]=s[j];
            tmp->v=times;
		}
		else
        {
            int j;
            for(j=0;j<=i;j++)
                if(tmp->next[id]->str[j]!=s[j])
                    break;
            if(j==i)
            {
                 tmp->next[id]->v+=times;
            }
            else
            {
                if(tmp->next[id]->v-times>0)
                    tmp->next[id]->v-=times;
                else
                {
                    tmp->next[id]->v=times;
                    for(int j=0;j<=i;j++)
                    tmp->next[id]->str[j]=s[j];
                }
            }
        }
		tmp = tmp->next[id];
		i++; //移到下一个字符
	}
}

char* searchTrie(TrieNode * root, char * str,int len)
{
	if (root == NULL)
		return 0;
	TrieNode * tmp = root;
	int i = 0, id;
	str[len-1]='\0';
	while (str[i])
	{
		id = str[i] - '0';
		if (tmp->next[id])
		{
			tmp = tmp->next[id];
		}
		else
			return 0;
		i++;
	}
	return tmp->str;
}
void change(char *str)
{
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='a'||str[i]=='b'||str[i]=='c')
            str[i]='2';
        if(str[i]=='d'||str[i]=='e'||str[i]=='f')
            str[i]='3';
        if(str[i]=='g'||str[i]=='h'||str[i]=='i')
            str[i]='4';
        if(str[i]=='j'||str[i]=='k'||str[i]=='l')
            str[i]='5';
        if(str[i]=='m'||str[i]=='n'||str[i]=='o')
            str[i]='6';
        if(str[i]=='p'||str[i]=='q'||str[i]=='r'||str[i]=='s')
            str[i]='7';
        if(str[i]=='t'||str[i]=='u'||str[i]=='v')
            str[i]='8';
        if(str[i]=='w'||str[i]=='x'||str[i]=='y'||str[i]=='z')
            str[i]='9';
    }
}
int main()
{
        int T;
        scanf("%d",&T);
        TrieNode * root=createTrieNode();
        for(int p=1;p<=T;p++)
        {
            int n;
            scanf("%d",&n);
            char s[101];
            char temp[101];
            int times;
            while(n--)
            {
                scanf("%s",&s);
                scanf("%d",&times);
                for(int i=0;i<strlen(s);i++)
                    temp[i]=s[i];
                change(temp);
                insertTrie(root,temp,s,times);
            }
            printf("Scenario #%d:\n",p);
            int m;
            scanf("%d",&m);
            char number[101];
            char last[101][101];
            for(int i=0;i<m;i++)
            {
                scanf("%s",number);
//                printf("number is %s\n",number);
                int len=strlen(number);

                for(int j=1;j<=len;j++)
                {

                    char abc=searchTrie(root,number,j);
                    printf("dsknsmcnkjvhdskvnlsvlkzsnxvbxkcvjsdmcx 1 %c  2\n",abc);
                    for(int v=0;v<j;v++)
                    {
                        last[j][v]=abc[v];
                    }
                }
                for(int j=0;j<len;j++)
                {
                    printf("%s\n",last[j]);
                }
                printf("\n");
            }
        }
}
