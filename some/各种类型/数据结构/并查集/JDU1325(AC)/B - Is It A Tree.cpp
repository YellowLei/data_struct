#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=10000;
int pre[maxn],in[maxn];

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
    int m,n,flag,T=1;
    while(1)
    {
        memset(pre,0,sizeof(pre));
        memset(in,0,sizeof(in));
        flag=0;
        while(scanf("%d%d",&m,&n),m+n)
        {
            if(m<0&&n<0)
                return 0;
            if(pre[m]==0)
                pre[m]=m;
            if(pre[n]==0)
                pre[n]=n;
            in[n]++;
            if(same(m,n))
                flag=1;
            join(m,n);
        }
        if(flag)
            printf("Case %d is not a tree.\n",T++);
        else
        {
            //只能有一个集合
            int k=0,wrong=0;
            for(int i=1;i<=maxn;i++)
            {
                if(pre[i]==i)
                {
                    k++;
                    if(k>1)
                    {
                        wrong=1;
                        break;
                    }
                }
                if(in[i]>1)
                {
                    wrong=1;
                    break;
                }
            }
            if(wrong)
                printf("Case %d is not a tree.\n",T++);
            else
                printf("Case %d is a tree.\n",T++);
        }
    }
    return 0;
}



