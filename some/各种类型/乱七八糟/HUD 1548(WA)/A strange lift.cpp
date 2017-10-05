#include<iostream>
#include<cstdio>
using namespace std;
const int maxhigh=201;
const int inf=999999;
int main()
{
    int N,A,B;
    int e[maxhigh][maxhigh],book[maxhigh],dis[maxhigh],k[maxhigh];
    while(scanf("%d",&N),N)
    {
        while(scanf("%d%d",&A,&B))
        {
            for(int i=1;i<=B;i++)
            {
                scanf("%d",&k[i]);
            }
            for(int i=1;i<=B;i++)
            {
                for(int j=1;j<=B;j++)
                {
                    if(i==j)
                        e[i][j]=0;
                    else
                        e[i][j]=inf;
                }
            }
            //转化为矩阵
            for(int i=1;i<=B;i++)
            {
                if(k[i]+i<=B)
                    e[i][i+k[i]]=1;
                if(i-k[i]>=1)
                    e[i][i-k[i]]=1;
            }
            for(int i=1;i<=B;i++)
            {
                dis[i]=e[A][i];
            }
            for(int i=1;i<=B;i++)
            {
                book[i]=0;
            }
            book[A]=1;

            for(int i=0;i<=B-1;i++)
            {
                int minn=inf;
                int u;
                for(int j=1;j<=B;j++)
                {
                    if(book[j]==0&&dis[j]<minn)
                    {
                        minn=dis[j];
                        u=j;
                    }
                }
                book[u]=1;
                for(int v=1;v<=B;v++)
                {
                    if(dis[v]>dis[u]+e[u][v])
                        dis[v]=dis[u]+e[u][v];
                }
            }
            if(dis[B]<inf)
                printf("%d\n",dis[B]);
            else
                printf("-1\n");
            break;
        }
    }
}
/*
//链表方式
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 999999999;
const int maxn = 200 +5;
struct Edge
{
    int from,to,dis,next;
};
Edge e[10000005];
int d[maxn];
int v[maxn];
int pre[maxn];

int main()
{
    int n,a,b,i,j,y;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        scanf("%d%d",&a,&b);
        int sum = 1;
        memset(v,0,sizeof(v));
        memset(pre,-1,sizeof(pre));
        for(i = 1;i <= n;i++)
        {
            scanf("%d",&y);
            if((i + y)>0&&(i + y) <= n)
            {
                e[sum].from = i;
                e[sum].to = i + y;
                e[sum].dis = 1;
                e[sum].next = pre[i];
                pre[i] = sum;
                sum++;
            }
            if((i - y)>0&&(i - y) <= n)
            {
                e[sum].from = i;
                e[sum].to = i - y;
                e[sum].dis = 1;
                e[sum].next = pre[i];
                pre[i] = sum;
                sum++;
            }
        }
        for(i = 1;i <= n;i++)
            d[i] = (i == a ? 0:INF);
        for(i = 1 ; i <= n; i++)
        {
            int x,minn=INF;
            for(j = 1; j <= n; j++)
                if(!v[j] && d[j] <= minn)
                    minn = d[x = j];
            v[x] = 1;
            for(j = pre[x] ;j != -1 ; j = e[j].next)
            {
                if(d[e[j].to] > d[x] + e[j].dis)
                    d[e[j].to] = d[x] + e[j].dis;
            }
        }
        d[b] = (d[b] == INF? -1:d[b]);
        cout << d[b] << endl;
    }
    return 0;
}


*/
