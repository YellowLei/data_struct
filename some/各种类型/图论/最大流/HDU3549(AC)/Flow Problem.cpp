#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;

const int maxn=20;
const int INF=9999999;

struct Edge
{
    int from,to,cap,flow;//cap为容量，flow为当时的流量
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct EdmondsKarp
{
    int m;
    vector<Edge> edges; //边数的两倍，有反向边
    vector<int> G[maxn];//邻接表，G[i][j]表示结点i的第j条边在edges数组中的序号
    int a[maxn];        //起点到i的可改进量
    int p[maxn];        //最短路径上p的入边编号

    //初始化
    void init(int n)
    {
        for(int i=0;i<n;i++)
            G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int cap)
    {
        //每条边和对对应的反向边保存在一起，边0和边2为反向边，2和3为反向边..
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0)); //反向边
        m=edges.size();         //加了两条边后的数量
        G[from].push_back(m-2); //正常边为加边后减2
        G[to].push_back(m-1);   //反向边是正常边的加1
    }

    int Maxflow(int s,int t)    //s为起点，t为终点
    {
        int flow=0;//初始流量为0
        while(1)
        {
            memset(a,0,sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s]=INF;   //起点到起点的可改进量无数
            //扩展结点时要递推出从s到每个节点i的路径上的最小残量
            while(!Q.empty())
            {
                int x=Q.front();
                Q.pop();
                for(int i=0;i<G[x].size();i++)
                {
                    Edge& e=edges[G[x][i]];
                    //printf("55555==%d\n",e.to);
                    if(!a[e.to]&&e.cap>e.flow)
                    {
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        Q.push(e.to);
                    }
                }
                if(a[t])    //a[t]是整条s—t道路上的最小残量，当a[t]不为0时，向下
                    break;
            }
            //可改进量为0后，退出
            if(!a[t])
                break;
            for(int u=t;u!=s;u=edges[p[u]].from)
            {
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];//边i的反向边是i^1
            }
            flow+=a[t];
        }
        return flow;
    }
};

int main()
{
    int T;
    scanf("%d",&T);
    EdmondsKarp ek;
    for(int k=1;k<=T;k++)
    {
        int N,M,from,to,cap;
        scanf("%d%d",&N,&M);
        ek.init(N);
        for(int i=1;i<=M;i++)
        {
            scanf("%d%d%d",&from,&to,&cap);
            ek.AddEdge(from,to,cap);
        }
        int ans=ek.Maxflow(1,N);
        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}
