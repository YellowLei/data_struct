#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;

int g[105][105];
bool visit[105];
int match[105];
int n;

int swap1[105*2],swap2[105*2];

bool dfs(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(g[u][i]==1&&!visit[i])
        {
            visit[i]=true;
            if(match[i]==-1||dfs(match[i]))
            {
                match[i]=u;
                return true;
            }
        }
    }
    return false;
}
int maxMatch()
{
    int sum=0;
    memset(match,-1,sizeof(match));
    for(int i=1;i<=n;i++)
    {
        memset(visit,false,sizeof(visit));
        if(dfs(i))
            sum++;
        else
            break;
    }
    return sum;
}
int main()
{
    int i,j,ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&g[i][j]);
            }
        }
        ans=maxMatch();
        if(ans!=n)
        {
            printf("-1\n");
            continue;
        }
        int type=0;
        for(i=1;i<=n;i++)
        {
            if(match[i]!=i)
            {
                for(j=i;j<=n;j++)
                {
                    if(match[j]==i)
                    {
                        match[j]=match[i];
                        match[i]=i;
                        swap1[++type]=i;
                        swap2[type]=j;
                    }
                }
            }
        }
        printf("%d\n",type);
        for(i=1;i<=type;i++)
        {
            printf("C %d %d\n",swap1[i],swap2[i]);
        }
    }
    return 0;
}
