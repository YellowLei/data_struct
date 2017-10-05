#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

const int MAX=35*35;

bool g[MAX][MAX];       //邻接矩阵，true代表有边相连
bool visit[MAX];        //记录二分图中右边的某个点是否被搜索过
int match[MAX];         //记录与二分图右边的点匹配的点的编号
int cnt;                //二分图中左边和右边集合中顶点的个数，此题中相等只用一个

bool hole[35][35];      //有没有洞的标记
int id[35][35];         //给每个点的编号，除有洞的点

//匈牙利算法，找增广路
bool dfs(int u)
{
    for(int i=1;i<=cnt;i++)
    {
        if(g[u][i]&&!visit[i])  //如果节点i与u相邻并且未被查找过
        {
            visit[i]=true;      //标记结点i被查找过
            if(match[i]==-1||dfs(match[i])) //如果结点i不在匹配中，或者i在匹配中，但从与i相邻的结点出发可以找到增广路
            {
                match[i]=u;     //记录查找成功记录，更新匹配M（即“取反”）
                return true;    //返回查找成功
            }
        }
    }
    return false;
}
//获得最大匹配数
int maxMatch()
{
    int i,sum=0;
    memset(match,-1,sizeof(match));
    for(int i=1;i<=cnt;i++)
    {
        memset(visit,false,sizeof(visit));  //清空上次搜索时的标记
        //从节点i尝试扩展
        if(dfs(i))
        {
            sum++;
        }
    }
    return sum;
}
int main()
{
    int i,j,m,n,k,x,y,ans;
    while(scanf("%d %d %d",&m,&n,&k)!=EOF)
    {
        memset(g,false,sizeof(g));
        memset(hole,false,sizeof(hole));
        //给有洞的点做标记
        for(i=1;i<=k;i++)
        {
            scanf("%d %d",&y,&x);
            hole[x][y]=true;        //在(x,y)上有洞
        }
        //剪枝，如果不是洞的点是奇数个，肯定不满足
        if((m*n-k)%2!=0)
        {
            printf("NO\n");
            continue;
        }

        //给不是洞的点编号
        cnt=0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(hole[i][j]==false)
                    id[i][j]=++cnt;
            }
        }

        //建图，注意边界
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(hole[i][j]==false)
                {
                    if(i-1>0&&hole[i-1][j]==false)
                    {
                        g[id[i][j]][id[i-1][j]]=true;
                    }
                    if(i+1<=m&&hole[i+1][j]==false)
                    {
                        g[id[i][j]][id[i+1][j]]=true;
                    }
                    if(j-1>0&&hole[i][j-1]==false)
                    {
                        g[id[i][j]][id[i][j-1]]=true;
                    }
                    if(j+1<=n&&hole[i][j+1]==false)
                    {
                        g[id[i][j]][id[i][j+1]]=true;
                    }
                }
            }
        }
        ans=maxMatch();
        // printf("ans==%d\ncnt==%d\n",ans,cnt);
        //二分图是单向的，i到j和j到i是两个匹配，所以匹配数应和点数相等
        if(ans==cnt)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
