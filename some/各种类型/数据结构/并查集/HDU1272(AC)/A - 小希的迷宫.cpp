#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int pre[100005];

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

bool same(int x,int y)
{
    return findFather(x)==findFather(y);
}

int main()
{
    int m,n,flag;
    while(scanf("%d%d",&m,&n),m+n!=-2)
    {
        memset(pre,0,sizeof(pre));
        flag=0;
        if(pre[m]==0)
            pre[m]=m;
        if(pre[n]==0)
            pre[n]=n;
        join(m,n);
        if(m+n!=0)
        {
            while(scanf("%d%d",&m,&n),m+n)
            {
                if(pre[m]==0)
                    pre[m]=m;
                if(pre[n]==0)
                    pre[n]=n;
                if(same(m,n))
                    flag=1;
                else
                    if(flag!=1)
                        join(m,n);
            }
        }
        //只能有一个集合
        int k=0;
        for(int i=1;i<=100005;i++)
        {
            if(pre[i]==i)
                k++;
            pre[i]=0;
        }
       // printf("k==%d\n",k);
        if(flag==0&&k<=1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}



