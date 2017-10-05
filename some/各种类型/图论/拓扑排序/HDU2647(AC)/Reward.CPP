#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 10005;
int val[maxn];
int in[maxn];
vector <int > G[maxn];
int n,m,sum,ans;

void topsort()
{
    queue <int > que;
    while(!que.empty())que.pop();
    for(int i = 1;i <= n;i++)
    {
        if(!in[i])	//这些人的奖金为888
            que.push(i);
    }
    while(!que.empty())
    {
        int u = que.front();que.pop();
		sum += val[u];
		ans++;
        for(int i = 0;i < G[u].size();i++)
        {
            int k = G[u][i];
            if(--in[k] == 0)
			{
				val[k] = val[u] + 1;
                que.push(k);
			}
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0;i < maxn;i++)
        {
            val[i] = 888;
            G[i].clear();
        }
        memset(in,0,sizeof(in));
		sum = 0;
		ans = 0;

        int from,to;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&to,&from);
            G[from].push_back(to);
            in[to]++;
        }
        topsort();
		if(ans != n)
			sum = -1;
        printf("%d\n",sum);
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 10001;
int val[maxn],in[maxn],head[maxn];
int sum,ans,n,m;

struct Node //链接表存边
{
    int to,next;
}edge[maxn<<1];

void topsort()
{
    queue <int >que;
    for(int i = 1;i <= n;i++)
    {
        if(in[i] == 0)  //入度为0表示这个人奖金就是888
            que.push(i);
    }
    while(!que.empty())
    {
        int u = que.front();que.pop();
        sum += val[u];
        ans++;  //用一个变量记录调用元素的总量，最后与n作比较
        for(int i = head[u];i != -1;i = edge[i].next)//与队首元素u有关的都枚举一遍
        {
            int k = edge[i].to;
            if(--in[k] == 0)    //如果入度-1为0，即为u的下一个元素
            {
                que.push(k);
                val[k] = val[u] + 1;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(head,-1,sizeof(head));
        memset(in,0,sizeof(in));
        for(int i=1; i<=n; i++)
            val[i]=888;//所有人一开始都为888
        sum=0;
        ans=0;

        int from,to,tot=0;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&to,&from);    //注意要逆过来，因为后一个from是基础的888，应当作为出度
            edge[tot].to = to;
            edge[tot].next = head[from];
            head[from] = tot++;
            in[to]++;   //入度
        }
        topsort();
        if(ans != n)
            sum = -1;
        printf("%d\n",sum);
    }
    return 0;
}
*/
