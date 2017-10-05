#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 505;
int G[maxn][maxn];  //矩阵存边
int index[maxn];    //入度
int vis[maxn];  //是否访问过
int topo[maxn]; //存topo的顺序
int n,m;

void topsort()
{
    int i,j,k,flag = 0;
    while(flag < n) //有n个点要存，可以从0到n-1，flag最后会加到n
    {
        for(i = 1;i <= n;i++)
        {
            if(!vis[i] && !index[i])    //没有访问过，且入度为0的编号最小的点进入topo
            {
                topo[flag++] = i;
                vis[i] = 1;
                break;
            }
        }
        for(j = 1;j <= n;j++)   //一个点出去后，以他为起点的边的终点的入读全部减1
        {
            if(G[i][j]) index[j]--;
        }
    }
    for(k = 0;k < n;k++)
        if(k != n -1)printf("%d ",topo[k]);
        else printf("%d\n",topo[k]);
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(G,0,sizeof(G));
        memset(index,0,sizeof(index));
        memset(vis,0,sizeof(vis));
        int from,to;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&from,&to);
            if(!G[from][to])    //可能会有重边，在很多图论里都要考虑这一点
            {
                G[from][to] = 1;
                index[to]++;    //终点的入度加一
            }
        }
        topsort();
    }
    return 0;
}
