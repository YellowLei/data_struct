#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 30005;
int in[maxn];
vector <int > G[maxn];
int topo[maxn];
int n,m,index,minn;

void topsort()
{
    priority_queue <int> que;
    while(!que.empty()) que.pop();
    for(int i = 1;i <= n;i++)
    {
        if(!in[i]) que.push(i);
    }
    while(!que.empty())
    {
        int u = que.top();que.pop();
        topo[index++] = u;
        for(int i = 0;i < G[u].size();i++)
        {
            int k = G[u][i];
            if(!(--in[k]))
                que.push(k);
        }
    }
}
int main()
{
    int T,from,to;
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 0;i < maxn;i++)G[i].clear();
        memset(in,0,sizeof(in));
        memset(topo,0,sizeof(topo));
        scanf("%d%d",&n,&m);
        index = 1;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&to,&from);
            G[from].push_back(to);
            in[to]++;
        }
        topsort();
        for(int i = n;i > 1;i--)
            printf("%d ",topo[i]);
        printf("%d\n",topo[1]);
    }
    return 0;
}
