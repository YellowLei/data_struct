#include<iostream>
#include<cstdio>

using namespace std;

const int MAX=50005;
int a[MAX],tree[MAX*4],p,add[MAX*4];
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
void PushUp(int root)
{
    tree[root]=tree[root*2]+tree[root*2+1];
}
void build(int root,int left,int right)
{
    add[root]=0;
    if(left==right)
    {
        tree[root]=a[p++];
        return ;
    }
    int mid=(left+right)/2;
    build(root*2,left,mid);
    build(root*2+1,mid+1,right);
    PushUp(root);
}
void update(int root,int m,int n,int left,int right)
{
    if(m==left&&right==left)
    {
        add[root]+=n;
        tree[root]+=n;
        return ;
    }
    PushDown(root,right-left+1);
    int mid=(left+right)/2;
    if(m<=mid)
        update(root*2,m,n,left,mid);
    else
        update(root*2+1,m,n,mid+1,right);
    PushUp(root);
}
int query(int root,int m,int n,int left,int right)
{
    if(m<=left&&right<=n)
    {
        return tree[root];
    }
    PushDown(root,right-left+1);
    int mid=(right+left)/2;
    int sum=0;
    if(m<=mid)
        sum+=query(2*root,m,n,left,mid);
    if(n>mid)
        sum+=query(2*root+1,m,n,mid+1,right);
    return sum;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int k=1;k<=T;k++)
    {
        int N,m,n;
        char oper[10];
        scanf("%d",&N);
        p=0;
        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);
        build(1,1,N);
        printf("Case %d:\n",k);
        while(true)
        {
            scanf("%s",oper);
            if(oper[0]=='E')
                break;
            scanf("%d%d",&m,&n);
            if(oper[0]=='Q')
                printf("%d\n",query(1,m,n,1,N));
            else if(oper[0]=='A')
                update(1,m,n,1,N);
            else if(oper[0]=='S')
                update(1,m,-n,1,N);
        }
    }
    return 0;
}
