//(1)：线段树的构造 void build(int node, int begin, int end);
//主要思想是递归构造，如果当前节点记录的区间只有一个值，则直接赋值，
//否则递归构造左右子树，最后回溯的时候给当前节点赋值

//查询区间最小值
#include <iostream>
using namespace std;

const int maxind = 256;
int segTree[maxind * 4 + 10];
int array[maxind];
/* 构造函数，得到线段树 */
void build(int node, int begin, int end)
{
    if (begin == end)
        segTree[node] = array[begin]; /* 只有一个元素,节点记录该单元素 */
    else
    {
        /* 递归构造左右子树 */
        build(2*node, begin, (begin+end)/2);
        build(2*node+1, (begin+end)/2+1, end);

        /* 回溯时得到当前node节点的线段信息 */
        if (segTree[2 * node] <= segTree[2 * node + 1])
            segTree[node] = segTree[2 * node];
        else
            segTree[node] = segTree[2 * node + 1];
    }
}

int main()
{
    array[0] = 1, array[1] = 2,array[2] = 2, array[3] = 4, array[4] = 1, array[5] = 3;
    build(1, 0, 5);
    for(int i = 1; i<=20; ++i)
     cout<< "seg"<< i << "=" <<segTree[i] <<endl;
    return 0;
}

//模板1
//查询区间最小值下标模板---min

#include<iostream>

using namespace std;

#define MAXN 100
#define MAXIND 256 //线段树节点个数

//构建线段树,目的:得到M数组.
void build(int node, int beginn, int endd, int segTree[], int arr[])
{
    if (beginn == endd)
        segTree[node] = beginn; //只有一个元素,只有一个下标
    else
    {
        build(2 * node, beginn, (beginn + endd) / 2, segTree, arr);
        build(2 * node + 1, (beginn + endd) / 2 + 1, endd, segTree, arr);

        if (arr[segTree[2 * node]] <= arr[segTree[2 * node + 1]])
            segTree[node] = segTree[2 * node];
        else
            segTree[node] = segTree[2 * node + 1];
    }
}

//找出区间 [i, j] 上的最小值的索引
int query(int node, int beginn, int endd, int segTree[], int arr[], int i, int j)
{
    int p1, p2;

    //查询区间和要求的区间没有交集
    if (i > endd || j < beginn)
        return -1;

    if (beginn >= i && endd <= j)
        return segTree[node];

    p1 = query(2 * node, beginn, (beginn + endd) / 2, segTree, arr, i, j);
    p2 = query(2 * node + 1, (beginn + endd) / 2 + 1, endd, segTree, arr, i, j);

    //return the position where the overall
    //minimum is
    if (p1 == -1)
        return segTree[node] = p2;
    if (p2 == -1)
        return segTree[node] = p1;
    if (arr[p1] <= arr[p2])
        return segTree[node] = p1;
    return segTree[node] = p2;

}


int main()
{
    int segTree[MAXIND]; //下标1起才有意义,否则不是二叉树,保存下标编号节点对应区间最小值的下标.
    memset(segTree,-1,sizeof(segTree));
    int a[]={3,4,5,7,2,1,0,3,4,5};
    build(1, 0, sizeof(a)/sizeof(a[0])-1, segTree, a);
    cout<<query(1, 0, sizeof(a)/sizeof(a[0])-1, segTree, a, 0, 5)<<endl;
    return 0;
}

模板2
连续区间修改或者单节点更新的动态查询问题 （此模板查询区间和）

#include <cstdio>
#include <algorithm>
using namespace std;

#define lson left , mid , root << 1
#define rson mid + 1 , right , root << 1 | 1
#define roott 1 , N , 1
#define LL long long
const int maxn = 111111;
LL add[maxn<<2];
LL sum[maxn<<2];
void PushUp(int root) {
    sum[root] = sum[root<<1] + sum[root<<1|1];
}
void PushDown(int root,int lengh)
{
    if (add[root])
	{
        add[root<<1] += add[root];
        add[root<<1|1] += add[root];
        sum[root<<1] += add[root] * (lengh - (lengh >> 1));
        sum[root<<1|1] += add[root] * (lengh >> 1);
        add[root] = 0;
    }
}
void build(int left,int right,int root)
{
    add[root] = 0;
    if (left == right)
	{
        scanf("%lld",&sum[root]);
        return ;
    }
    int mid = (left + right) >> 1;
    build(lson);
    build(rson);
    PushUp(root);
}
void update(int L,int R,int c,int left,int right,int root)
{
    if (L <= left && right <= R)
	{
        add[root] += c;
        sum[root] += (LL)c * (right - left + 1);
        return ;
    }
    PushDown(root , right - left + 1);
    int mid = (left + right) >> 1;
    if (L <= mid) update(L , R , c , lson);
    if (mid < R) update(L , R , c , rson);
    PushUp(root);
}
LL query(int L,int R,int left,int right,int root)
{
    if (L <= left && right <= R)
	{
        return sum[root];
    }
    PushDown(root , right - left + 1);
    int mid = (left + right) >> 1;
    LL ret = 0;
    if (L <= mid) ret += query(L , R , lson);
    if (mid < R) ret += query(L , R , rson);
    return ret;
}
int main()
{
    int N , Q;
    scanf("%d%d",&N,&Q);
    build(roott);
    while (Q --)
	{
        char op[2];
        int a , b , c;
        scanf("%s",op);
        if (op[0] == 'Q')
		{
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(a , b ,roott));
        } else {
            scanf("%d%d%d",&a,&b,&c);
            update(a , b , c , roott);
        }
    }
    return 0;
}
