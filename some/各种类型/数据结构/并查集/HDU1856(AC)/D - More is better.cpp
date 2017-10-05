#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=10000005;
int pre[maxn],num[maxn];
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
    {
        pre[fx]=fy;
        num[fy]+=num[fx];  //fx的朋友全部是fy的朋友
    }
}
int main()
{
    int N;
    while(~scanf("%d",&N))
    {
        if(N==0)
        {
            printf("1\n");
            continue;
        }
        int m,n,maxx=0,people=0;
        for(int i=1;i<=maxn;i++)
        {
            pre[i]=i;
            num[i]=1;
        }
        while(N--)
        {
            scanf("%d%d",&m,&n);
            if(people<m) people=m;
            if(people<n) people=n;
            join(m,n);
        }
        for(int i=1;i<=people;i++)
        {
            if(num[i]>maxx)
                maxx=num[i];
        }
        printf("%d\n",maxx);
    }
    return 0;
}
