//对于某一区间 ，我们保存以从该区最左边点为起点的最长子序列长度，
//和以该区间最右边的点为终点的最长子序列，以及该区间的最长子序列。
//对于中点mid 如果a[mid]>=a[mid+1]断开,那么有左边最长=左儿子左边最长
//右边最长=右儿子右边最长 ,全局最长=Max(两个儿子的全局最长)
#include<iostream>
#include<cstdio>
#include <cstdlib>

using namespace std;

const int MAX=100005;
int num[MAX],sum[MAX*4],leftSum[MAX*4],rightSum[MAX*4];
void PushUp(int root,int left,int right)
{
    leftSum[root]=leftSum[root*2];
    rightSum[root]=rightSum[root*2+1];
    sum[root]=0;
    int mid=(left+right)/2;
    if(num[mid]<num[mid+1])
    {
        if(leftSum[root]==mid-left+1)
            leftSum[root]+=rightSum[root*2+1];
        if(rightSum[root]==right-mid)
            rightSum[root]+=leftSum[root*2];
        sum[root]=leftSum[root*2]+rightSum[root*2+1];
    }
    sum[root]=max(sum[root],max(sum[root*2],sum[root*2+1]));
}

void update(int root,int left,int right,int m,int val)
{
    if(m==left&&right==left)
    {
        num[m]=val;
    }
    else
    {
        int mid=(right+left)/2;
        if(m<=mid)
            update(root*2,left,mid,m,val);
        else
            update(root*2+1,mid+1,right,m,val);
        PushUp(root,left,right);
    }

}
void build(int root,int left,int right)
{
    if(left==right)
        sum[root]=leftSum[root]=rightSum[root]=1;
    else
    {
        int mid=(left+right)/2;
        build(root*2,left,mid);
        build(root*2+1,mid+1,right);
        PushUp(root,left,right);
    }
}
int query(int root,int left,int right,int m,int n)
{
    if(m<=left&&right<=n)
     {
         return sum[root];
     }
    else
    {
        int mid=(left+right)/2;
        if(n<=mid)
        {
            return query(root*2,left,mid,m,n);
        }
        else if(m>mid)
        {
            return query(root*2+1,mid+1,right,m,n);
        }
        else
        {
            int x,y,len;
            x=query(root*2,left,mid,m,n);
            y=query(root*2+1,mid+1,right,m,n);
            if(num[mid]<num[mid+1])
                len=min(rightSum[root*2],mid-left+1)+min(leftSum[root*2+1],right-mid);
            len=max(len,max(x,y));
            return len;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M,n,m;
        char oper[3];
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)
            scanf("%d",&num[i]);
        for(int i=0;i<M;i++)
        {
            scanf("%s%d%d",oper,&m,&n);
            if(oper[0]=='Q')
                printf("%d\n",query[1,1,N,m+1,n+1]);
            else
                update(1,1,N,m+1,n);
        }

    }
    return 0;
}
/*
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 100000;
struct node
{
    int left;
    int right;
    int sumLeft;
    int sumRight;
    int sum;
} tree[MAXN*4+10];
int num[MAXN+10];
void PushUp(int root)
{
    int left = root*2;
    int right = root*2+1;
	//左右断开的情况num[mid] >= num[mid+1]
    tree[root].sumLeft = tree[left].sumLeft;
    tree[root].sumRight = tree[right].sumRight;
    tree[root].sum = 0;
    int mid = (tree[root].left + tree[root].right)/2;
    if (num[mid] < num[mid+1]) 	//左右可以连起来的情况
	{
        if (tree[root].sumLeft == tree[left].right - tree[left].left + 1)//左边最长=左儿子长度(表示左半全是最长递增子序列)
            tree[root].sumLeft += tree[right].sumLeft;//左边最长+=右儿子左边最长
        if (tree[root].sumRight == tree[right].right - tree[right].left + 1)//右边最长=右儿子长度
            tree[root].sumRight += tree[left].sumRight;//右边最长+=左儿子右边最长
        tree[root].sum = tree[left].sumRight + tree[right].sumLeft;//用左儿子右边最长+右儿子左边最长更新全局最长(中间连起来的)
    }
    tree[root].sum = max(tree[root].sum, max(tree[left].sum, tree[right].sum));//选最长的
}
void build(int root, int left, int right)
{
    tree[root].left = left;
    tree[root].right = right;
    if (left==right)
        tree[root].sumLeft = tree[root].sumRight = tree[root].sum = 1;
    else
    {
        int mid = (left + right)/2;
        build(root *2, left, mid);
        build(root*2+1,mid+1, right);
        PushUp(root);
    }
}
void update(int root, int left, int right, int val)
{
    if (tree[root].left == left && tree[root].right == right)
	{
        num[tree[root].left] = val;
		return ;
    }
	else
	{
        int mid = (tree[root].left + tree[root].right) /2;
        if (right <= mid)
            update(root *2, left, right, val);
        else
            update(root*2 +1, left, right, val);
        PushUp(root);
    }
}
int query(int root, int left, int right)
{
    if (tree[root].left == left && tree[root].right == right)
	{
        return tree[root].sum;
    }
    else
	{
        int mid = (tree[root].left + tree[root].right)/2;
        if (right <= mid)
            return query(root*2, left, right);
        else if (left > mid)
            return query((root *2) +1, left, right);
        else
		{
			int tmp;
            if (num[mid] < num[mid + 1])
			{
                tmp = min(mid - left + 1, tree[root *2].sumRight) + min(right - mid, tree[(root *2) +1].sumLeft);
            }
            return max(tmp,max(query(root *2, left, mid), query((root *2) + 1, mid + 1, right)));
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
	{
        int n, m;
        scanf("%d%d", &n, &m);
        int i(0);
        int tmp;
        for (i = 1; i <= n; ++i)
		{
            scanf("%d", num + i);
        }
        build(1, 1, n);
        char cmd[2];
        int a, b;
        while (m--)
		{
            scanf("%s", cmd);
            if (cmd[0] == 'Q')
			{
                scanf("%d%d", &a, &b);
                printf("%d\n", query(1, a + 1, b + 1));
            } else {
                scanf("%d%d", &a, &b);
                update(1, a + 1, a + 1, b);
            }
        }
    }
    return 0;
}
*/
