#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;

bool g[105][105];
bool visit[105];
int match[105];
int n,m;

int x[105*105];
int y[105*105];

int dfs(int u)
{
    for(int i=1;i<=m;i++)
    {
        if(g[u][i]&&!visit[i])
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
    int i,sum=0;
    memset(match,-1,sizeof(match));
    for(i=1;i<=n;i++)
    {
        memset(visit,false,sizeof(visit));
        if(dfs(i))
            sum++;
    }
    return sum;
}

int main()
{
    int k,i,j,ans,tmp,imp;
    int T=1;
    while(scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
        memset(g,false,sizeof(g));
        memset(x,-1,sizeof(x));
        memset(y,-1,sizeof(y));
        for(i=1;i<=k;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            g[x[i]][y[i]]=true;
        }
        ans=maxMatch();
        imp=0;
        for(i=1;i<=k;i++)
        {
            g[x[i]][y[i]]=false;
            tmp=maxMatch();
            if(tmp<ans)
            {
                imp++;
            }
            g[x[i]][y[i]]=true;
        }
       printf("Board %d have %d important blanks for %d chessmen.\n",T++,imp,ans);

    }
    return 0;
}
