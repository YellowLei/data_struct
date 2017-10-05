#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100005;
int in[maxn];
vector <int > G[maxn];
int m,n,res,from,to;
long long ans;

void topsort()
{
    priority_queue <int > que; //优先级队列，从大到小
    while(!que.empty())que.pop();
    for(int i = 1;i <= n;i++)
    {
        if(in[i] == 0)
            que.push(i);
    }
    while(!que.empty())
    {
        int u = que.top();que.pop();
        res = min(res,u);   //前面最小的
        ans += res;
        for(int i = 0;i < G[u].size();i++)
        {
            int k = G[u][i];
            if(--in[k] == 0)    //u已经放到前面了，出度为u的入度可以入队了
                que.push(k);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 1;i <= maxn;i++)G[i].clear();
        memset(in,0,sizeof(in));
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&from,&to);
            G[from].push_back(to);
            in[to]++;
        }
        ans = 0;res = n;
        topsort();
        printf("%I64d\n",ans);
    }
    return 0;
}
