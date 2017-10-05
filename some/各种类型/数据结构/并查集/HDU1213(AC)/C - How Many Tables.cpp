#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int pre[1005];
int findFather(int x)
{
    if(pre[x]!=x)
        pre[x]=findFather(pre[x]);
    return pre[x];
}
void join(int x,int y)
{
    int fx=findFather(x);
    int fy=findFather(y);
    if(fx!=fy)
        pre[fx]=fy;
}
bool same(int x,int  y)
{
    return findFather(x)==findFather(y);
}
int main()
{
    int T,M,N,m,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&M,&N);
        for(int i=1;i<=M;i++)
        {
            pre[i]=i;
        }
        while(N--)
        {
            scanf("%d%d",&m,&n);
            join(m,n);
        }
        int k=0;
        for(int i=1;i<=M;i++)
        {
            if(pre[i]==i)
                k++;
        }
        printf("%d\n",k);
    }
    return 0;
}
