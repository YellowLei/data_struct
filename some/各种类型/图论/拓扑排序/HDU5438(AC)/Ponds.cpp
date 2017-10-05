#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 10010;
typedef long long  LL;
LL val[maxn];
int vis[maxn];
LL in[maxn];
vector <LL> G[maxn];
int n,m;

void topsort()
{
    queue<LL> que;
    while(!que.empty())que.pop();
    for(int i = 1;i <= n;i++)
    {
        if(in[i] <=1)
        {
            if(in[i] == 1)que.push(i);
            vis[i] = 1;
        }
    }
    while(!que.empty())
    {
        LL u = que.front();que.pop();
        for(int i = 0;i < G[u].size();i++)
        {
            LL k = G[u][i];
            if(--in[k] <= 1)
            {
                if(in[k] == 1)que.push(k);
                vis[k] = 1;
            }
        }
    }
}

LL dfs(int u)
{
    queue<LL> que;
    que.push(u);
    vis[u] = 1;
    LL sum = 0;
    LL len = 0;
    while(!que.empty())
    {
        LL u = que.front();
        que.pop();
        sum += val[u];
        len++;
        for(int i = 0;i < G[u].size();i++)
        {
            LL k = G[u][i];
            if(!vis[k])
            {
                que.push(k);
                vis[k] = 1;
            }
        }
    }
    if(len & 1) return sum;
    else return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        memset(val,0,sizeof(val));
        for(int i = 0;i < maxn;i++)
            G[i].clear();
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
            scanf("%I64d",&val[i]);
        int from,to;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&from,&to);
            G[from].push_back(to);
            G[to].push_back(from);
            in[from]++;
            in[to]++;
        }
        topsort();
        LL sum = 0;
        for(int i = 1;i <= n;i++)
        {
            if(!vis[i]) sum += dfs(i);
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
