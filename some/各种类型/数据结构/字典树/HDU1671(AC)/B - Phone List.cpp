#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10005;
const int Max=10;
bool flag=false;
typedef struct TrieNode
{
    int v;
    bool isPhone;
    TrieNode *next[Max];
};
TrieNode * createTrieNode()
{
    TrieNode * tmp=(TrieNode*)malloc(sizeof(TrieNode));
    tmp->v=1;
    tmp->isPhone=false;
    for(int i=0;i<Max;i++)
        tmp->next[i]=NULL;
    return tmp;
}
void  insertTrie(TrieNode * root,char *str)
{
    TrieNode *tmp=root;
    int i=0;
    while(str[i]!='\0')
    {
        int id=str[i]-'0';   //id表示它的字符
        if(tmp->next[id]!=NULL)
        {
            tmp->next[id]->v++;

        }
        else
        {
            tmp->next[id]=createTrieNode();
        }
        if(tmp->isPhone==true)
            flag=true;
        tmp=tmp->next[id];
        i++;
    }
    tmp->isPhone=true;
    if(tmp->v!=1)
        flag=true;
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
int main()
{
    int T,n;
    char s[11];
    int m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        TrieNode *root = createTrieNode();
        flag=false;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(flag!=true)
                insertTrie(root,s);
        }
        if(flag==true)
            printf("NO\n");
        else printf("YES\n");
        dealTrie(root);
    }
}

