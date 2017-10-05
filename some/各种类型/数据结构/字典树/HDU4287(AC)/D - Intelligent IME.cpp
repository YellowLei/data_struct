#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<cstring>
using namespace std;
const int Max=10;
const int maxn=5005;
typedef struct TrieNode
{
    int v;
    TrieNode *next[Max];
};
TrieNode* createTrieNode()
{
    TrieNode *tmp=(TrieNode*)malloc(sizeof(TrieNode));
    tmp->v=1;
    for(int i=0;i<Max;i++)
    {
        tmp->next[i]=NULL;
    }
    return tmp;
}
void insertTrie(TrieNode *root,char *str)
{
    TrieNode *tmp=root;
    int i=0,id;
    while(str[i]!='\0')
    {
        id=str[i]-'0';
        if(tmp->next[id])
        {
            tmp->next[id]->v++;
        }
        else
        {
            tmp->next[id]=createTrieNode();
        }
        tmp=tmp->next[id];
        i++;
    }
}
int searchTrie(TrieNode* root,char* str)
{
    if(root==NULL)
        return 0;
    TrieNode *tmp=root;
    int i=0,id;
    while(str[i])
    {
        id=str[i]-'0';
        if(tmp->next[id])
        {
            tmp=tmp->next[id];
        }
        else
            return 0;
        i++;
    }
    return tmp->v;
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
    while(T--)
    {
        int m,n;
        char s[7];
        char p[maxn][7];
        scanf("%d%d",&n,&m);
        getchar();
        TrieNode * root=createTrieNode();
        for(int i=0;i<n;i++)
        {
            scanf("%s",p[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%s",s);
            change(s);
            insertTrie(root,s);
        }
        for(int i=0;i<n;i++)
        {
            printf("%d\n",searchTrie(root,p[i]));
        }

    }
}
