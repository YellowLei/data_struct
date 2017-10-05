#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 33;

struct node
{
    int x,y,z;
    node(int x = 0,int y = 0,int z = 0):x(x),y(y),z(z){}
    bool operator == (const node& rhs)const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }
}S,E;

int l,r,c;
int vis[maxn][maxn][maxn];  //标记，-1表示没有走过，其他的表示走到这里所需的步数
char Map[maxn][maxn][maxn];
int dz[] = {0,0,0,0,1,-1};
int dx[] = {0,1,0,-1,0,0};
int dy[] = {1,0,-1,0,0,0};

int bfs(node S)
{
    queue <node> q;
    q.push(S);  //起点入队
    memset(vis,-1,sizeof(vis));
    vis[S.z][S.x][S.y] = 0;
    while(!q.empty())
    {
        node u = q.front();
        q.pop();
        if(u == E)
            return vis[u.z][u.x][u.y];
        for(int i = 0;i < 6;i++)
        {
            int x = u.x + dx[i],y = u.y + dy[i],z = u.z + dz[i];    //留个方向搜索
            if(z < 1 || z > l || x < 1 || x > r || y < 1 || y > c) continue;    //边界考虑
            node v = node(x,y,z);
            if(Map[z][x][y] == '.' && vis[z][x][y] == -1)
            {
                vis[z][x][y] = vis[u.z][u.x][u.y] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    while(scanf("%d%d%d",&l,&r,&c))
    {
        if(l == 0 && r == 0 && c == 0)break;
        for(int i = 1;i <= l;i++)
           for(int j = 1;j <= r;j++)
                scanf("%s",Map[i][j] + 1);
        for(int i = 1;i <= l;i++)
            for(int j = 1;j <= r;j++)
                for(int k = 1;k <= c;k++)
                    if(Map[i][j][k] == 'S'){S = node(j,k,i);Map[i][j][k] = '.';}
                    else if(Map[i][j][k] == 'E'){E = node(j,k,i);Map[i][j][k] = '.';}
        int ans = bfs(S);
        if(ans == -1)
            printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
