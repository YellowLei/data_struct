#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1010;

int e[maxn][maxn],dis[maxn],book[maxn];
int inf = 99999999;

int main()
{
    int n,m,c,d,k;
    int t1,t2,t3;
    int u,v,minn;
    while(scanf("%d %d %d %d %d",&n,&m,&c,&d,&k)!=EOF)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(i == j)
                    e[i][j] = 0;
                else e[i][j] = inf;
            }
        }

        for(int i = 1;i <= m;i++)
        {
            scanf("%d %d %d",&t1,&t2,&t3);
            if(t3 < e[t1][t2])
                e[t1][t2] = t3;
        }

        ////初始化顶点c到各点的距离
        for(int i = 1;i <= n;i++)
        {
            dis[i] = e[c][i];
        }

        for(int i = 1;i <= n;i++)
        {
            book[i] = 0;
        }
        book[c] = 1;

        for (int i = 1; i <= n-1; i++)
        {
            minn = inf;
            for (int j = 1; j<= n; j++)
            {
                if (book[j] == 0 && dis[j] < minn)
                {
                    minn = dis[j];
                    u = j;
                }
            }
            book[u] = 1;

            for (v = 1; v <= n; v++)
            {
                if (e[u][v] < inf)
                {
                    if (dis[v]>dis[u] + e[u][v])
                    {
                        dis[v] = dis[u] + e[u][v];
                    }
                }
            }
        }

        if(dis[d] <= k)
            printf("%d\n",dis[d]);
        else printf("Sorry\n");
    }
    return 0;
}
