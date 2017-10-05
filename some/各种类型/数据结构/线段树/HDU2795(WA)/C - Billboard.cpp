#include<iostream>
#include<cstdio>

using namespace std;

const int MAX=200005;
int h,w,n;
int tree[4*MAX],add[4*MAX];
//算根节点大小
void PushUp(int root)
{
    tree[root]=tree[2*root]+tree[2*root+1];
}
//更改根节点大小，add[]向下移
void PushDown(int root,int lenth)
{
    if(add[root])
    {
        add[root*2]+=add[root];
        add[root*2+1]+=add[root];
        tree[root*2]+=add[root]*(lenth-lenth/2);
        tree[root*2+1]+=add[root]*(lenth/2);
        add[root]=0;
    }
}
void build(int root,int left,int right)
{
    add[root]=0;
    if(left==right)
    {
        tree[root]=w;
        return;
    }
    int mid=(left+right)/2;
    build(root*2,left,mid);
    build(root*2+1,mid+1,right);
    PushUp(root);
}

int update(int root,int left,int right,int width)
{
    if(left==right&&tree[root]>=width)
    {
        add[root]+=-width;
        tree[root]-=width;
        return left;
    }
    int ans=0;
    PushDown(root,right-left+1);
    int mid=(left+right)/2;
    if(tree[root*2]>=width)
        ans=update(root*2,left,mid,width);
    else if(tree[root*2+1]>=width)
        ans=update(root*2+1,mid+1,right,width);
    PushUp(root);
    if(ans>0)
        return ans;
    else
        return -1;
}
int main()
{
    int v=1;
    while(~scanf("%d%d%d",&h,&w,&n),v<=40)
    {
        v++;
        int width;
        int minn;
        if(h<n)
            minn=h;
        else
            minn=n;

        build(1,1,minn);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&width);
            printf("%d\n",update(1,1,minn,width));
        }
    }
    return 0;
}
