#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

//注意 f数组要按从小到大排序 SG函数要初始化为-1 对于每个集合只需初始化1遍
//n是集合f的大小 f[i]是定义的特殊取法规则的数组
int f[110],sg[10010],n;
int SG_dfs(int x)
{
    int i;
    if(sg[x]!=-1)
        return sg[x];
    bool vis[110];
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
    {
        //当数字x大于操作数f[i]的时候才可能进行
        if(x>=f[i])
        {
            SG_dfs(x-f[i]);
            vis[sg[x-f[i]]]=1;//子问题
        }
    }
    for(i=0;;i++)
        if(vis[i]==0)
        {
            sg[x]=i;
            break;
        }
    return sg[x];
}

int main()
{
    int m,t,h;
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&f[i]);
        }
        memset(sg,-1,sizeof(sg));
        sort(f,f+n);
        scanf("%d",&m);
        while(m--)
        {
            int ans=0;
            scanf("%d",&t);
            while(t--)
            {
                scanf("%d",&h);
                ans^=SG_dfs(h);
            }
            //必败
            if(ans==0)
                printf("L");
            else
                printf("W");
        }
        printf("\n");
    }
    return 0;
}
/*
//自己写的，超时
#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;

int f[110],sg[11000],tmp[11000];

void getsg(int n,int k)
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=n;i++)
    {
        memset(tmp,0,sizeof(tmp));
        for(j=1;f[j]<=i&&j<=k;j++)
            tmp[sg[i-f[j]]]=1;
        for(j=0;j<=n;j++)
        {
            if(tmp[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }

}

int main()
{
    int k,m,n,h;
    while(scanf("%d",&k)&&k)
    {
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&f[i]);
        }
        getsg(11000,k);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int ans=0;
            scanf("%d",&n);
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&h);
                ans=(ans^sg[h]);
            }
            if(ans==0)
                printf("L");
            else
                printf("W");
        }
        printf("\n");
    }
    return 0;
}
*/

