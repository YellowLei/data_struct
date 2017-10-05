#include<iostream>
#include<cstdio>

using namespace std;

int tree[100005*4],renew[100005*4];
void PushUp(int root)
{
    tree[root]=tree[root*2]+tree[root*2+1];
}
void PushDown(int root,int length)
{
    if(renew[root])
    {
        renew[root*2]=renew[root];
        renew[root*2+1]=renew[root];
        tree[root*2]=renew[root]*(length-length/2);
        tree[root*2+1]=renew[root]*(length/2);
        renew[root]=0;
    }
}

void build(int root,int left,int right)
{
    renew[root]=0;
    if(left==right)
    {
        tree[root]=1;
        return ;
    }
    int mid=(left+right)/2;
    build(root*2,left,mid);
    build(root*2+1,mid+1,right);
    PushUp(root);
}
void update(int root,int left,int right,int m,int n,int v)
{
    if(m<=left&&right<=n)
    {
        renew[root]=v;
        tree[root]=v*(right-left+1);
        return;
    }
    PushDown(root,right-left+1);
    int mid=(right+left)/2;
    if(m<=mid)
        update(root*2,left,mid,m,n,v);
    if(mid<n)
        update(root*2+1,mid+1,right,m,n,v);
    PushUp(root);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int k=1;k<=T;k++)
    {
        int N,Q;
        scanf("%d%d",&N,&Q);
        build(1,1,N);
        for(int i=0;i<Q;i++)
        {
            int m,n,v;
            scanf("%d%d%d",&m,&n,&v);
            update(1,1,N,m,n,v);
        }
        printf("Case %d: The total value of the hook is %d.\n",k,tree[1]);
    }
    return 0;
}
