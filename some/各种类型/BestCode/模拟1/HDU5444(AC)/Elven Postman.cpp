//一般的 更快
#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
    int value;
    Node *left,*right;
}*root,*p,*q;

void build(int value)
{
    p = new Node;
    p = root;
    while(value != 0)
    {
        if(p->value == 0) //这个结点没有访问
        {
            p->value = value;
            value = 0;
        }
        else if(value < p->value)
        {
            if(p->left == NULL)
            {
                q = new Node;
                p->left = q;
                p = q;
                p->value = 0;
                p->left = p->right = NULL;

            }
            else p = p->left;
        }
        else if(value > p->value)
        {
            if(p->right == NULL)
            {
                q = new Node;
                p->right = q;
                p = q;
                p->value = 0;
                p->left = p->right = NULL;

            }
            else p = p -> right;
        }
    }
}
void dfs(int value)
{
    p = root;
    while(p->value != value)
    {
        if(p->value > value)
        {
            printf("E");
            p = p->left;
        }
        else
        {
            printf("W");
            p = p->right;
        }
    }
}
int main()
{
    int T,n,rt,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        root = new Node;
        root->value = 0;
        root->left = root->right = NULL;
        while(n--)
        {
            scanf("%d",&rt);
            build(rt);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&rt);
            dfs(rt);
            printf("\n");
        }
    }
    return 0;
}
/*
//递归搜索二叉树算法
#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
    int value;
    Node *left,*right;
    Node(){}
    Node(int n){value = n;left = right = NULL;}
};

void Insert(Node *&p,int value)
{
    if(value < p->value)
    {
        if(p->left == NULL)
        {
            p->left = new Node(value);
            return;
        }
        else Insert(p->left,value);
    }
    else
    {
        if(p->right== NULL)
        {
            p->right = new Node(value);
            return;
        }
        else Insert(p->right,value);
    }
}

void Find(Node *&p,int value)
{
    if(value == p->value)
    {
        printf("\n");
        return;
    }
    else if(value < p->value)
    {
        printf("E");
        Find(p->left,value);
    }
    else
    {
        printf("W");
        Find(p->right,value);
    }
}
int main()
{
    int T,n,rt,q;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&rt);
        Node *root = new Node(rt);
        for(int i = 1;i < n;i++)
        {
            scanf("%d",&rt);
            Insert(root,rt);
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&rt);
            Find(root,rt);
        }
    }
    return 0;
}
*/
