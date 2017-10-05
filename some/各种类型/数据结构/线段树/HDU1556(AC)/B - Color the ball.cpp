#include<iostream>
#include<cstdio>

using namespace std;

const int MAX=100005;
int tree[MAX*4],add[MAX*4];
void PushUp(int root)
{
    tree[root]=tree[root*2]+tree[root*2+1];
}
void PushDown(int root,int length)
{
    if(add[root])
    {
        add[root*2]+=add[root];
        add[root*2+1]+=add[root];
        tree[root*2]+=add[root]*(length-length/2);
        tree[root*2+1]+=add[root]*(length/2);
        add[root]=0;
    }
}
void build(int root,int left,int right)
{
    add[root]=0;
    if(left==right)
    {
        tree[root]=0;
        return;
    }
    int mid=(left+right)/2;
    build(2*root,left,mid);
    build(2*root+1,mid+1,right);
    PushUp(root);
}
void update(int root,int left,int right,int m,int n,int value)
{
    if(m<=left&&right<=n)
    {
        add[root]+=value;
        tree[root]+=value*(right-left+1);
        return ;
    }
    PushDown(root,right-left+1);//add[]向下移
    int mid=(left+right)/2;
    if(m<=mid)
        update(2*root,left,mid,m,n,value);
    if(mid<n)
        update(2*root+1,mid+1,right,m,n,value);
    PushUp(root);
}
int query(int root,int left,int right,int m,int n)
{
    if(m<=left&&right<=n)
    {
        return tree[root];
    }
    PushDown(root,right-left+1);//add[]向下移
    int mid=(right+left)/2;
    int sum=0;
    if(m<=mid)
        sum+=query(2*root,left,mid,m,n);
    if(n>mid)
        sum+=query(2*root+1,mid+1,right,m,n);
    return sum;
}
int main()
{
    int N,m,n;
    while(~scanf("%d",&N),N)
    {
        build(1,1,N);
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&m,&n);
            update(1,1,N,m,n,1);
        }
        for(int i=1;i<N;i++)
        {
            printf("%d ",query(1,1,N,i,i));
        }
        printf("%d\n",query(1,1,N,N,N));
    }
    return 0;
}
