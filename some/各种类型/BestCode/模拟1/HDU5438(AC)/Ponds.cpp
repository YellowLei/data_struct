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
vector <LL> G[maxn];    //G[i][j]存的是起点的i，终点是G[i][j]
int n,m;

void topsort()
{
    queue<LL> que;
    while(!que.empty())que.pop();
    //先使队列中有元素
    for(int i = 1;i <= n;i++)
    {
        if(in[i] <=1)
        {
            if(in[i] == 1)que.push(i);  //为1时还有相连的边，需入队减少与其相连点的入度
            vis[i] = 1; //为0时直接删除
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
        LL u = que.front();que.pop();
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
    //判断奇偶
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
        for(int i = 0;i < maxn;i++)G[i].clear();
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
/*
//博客中用链接表写的，没看懂，head不知道是什么
#include <stdio.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N=1e5+10;

struct node
{
    int to,next;
}edge[N*2];
int tot,head[N];

int n,m;
bool vis[N];
int in[N];
int val[N];

void add_edge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

void topsort()
{
    queue<int >que;
    while(!que.empty()) que.pop();
    for(int i=1; i<=n; ++i)
        if(in[i]<=1) que.push(i);
    while(!que.empty())
	{
        int u=que.front();que.pop();vis[u]=true;
        for(int i=head[u]; i!=-1; i=edge[i].next)
		{
            int k=edge[i].to;
            if(!vis[k])
			{
               if(--in[k]<=1) que.push(k);
            }
        }
    }
}

LL len,sum;
void dfs(int u)
{
    vis[u]=true;
    len++;
    sum+=val[u];
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int k=edge[i].to;
        if(!vis[k]){
            dfs(k);
        }
    }
}

int main()
{
    int t;scanf("%d",&t);
    while(t--)
	{
        tot=0;
		memset(head,-1,sizeof(head));
		memset(vis,false,sizeof(vis));
		memset(in,0,sizeof(in));

        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; ++i) scanf("%d",&val[i]);
        while(m--)
		{
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
            in[u]++;in[v]++;
        }
     topsort();
     LL ans=0;
     for(int i=1; i<=n; ++i)
	 {
         if(!vis[i])
		 {
            len=0;
            sum=0;
            dfs(i);
            if(len&1) ans+=sum;
         }
     }
     printf("%lld\n",ans);
    } return 0;
}

*/
