#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10;
char Map[maxn][maxn];
int vis[maxn];
int ans,n,k;

void dfs(int x,int y)
{
    if(y == k)
    {
        ans++;
        return;
    }
    if(x == n)
        return;
    for(int i = 0;i < n;i++)
    {
        if(Map[x][i] == '#' && vis[i] == 0)
        {
            vis[i] = 1;
            dfs(x+1,y+1);
            vis[i] = 0;
        }
    }
    dfs(x+1,y);
}
int main()
{
    while(scanf("%d%d",&n,&k) != EOF)
    {
        if(n == -1 && k == -1)
            break;
        getchar();
        for(int i = 0;i < n;i++)
            scanf("%s",Map[i]);
        ans = 0;
        memset(vis,0,sizeof(vis));
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
