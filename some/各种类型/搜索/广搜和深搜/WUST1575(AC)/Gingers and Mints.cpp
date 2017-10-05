#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 105;

int vis[maxn][maxn];
char pic[maxn][maxn];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int n,m;

void dfs(int x,int y)
{
    int nx,ny;
    for(int i=0;i<4;i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if(vis[nx][ny] == 0 && pic[nx][ny] == 'Y' && nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            vis[nx][ny] = 1;
            dfs(nx,ny);
        }
    }
}

//C{n,1} + C{n,3} + C{n,5} + ... = 2^(n-1) 用快速幂求出
int pow_mod(int a,int n,int m)
{
    if(n == 0)
        return 1;
    int x = pow_mod(a,n/2,m);
    long long ans = (long long )x*x%m;
    //奇数项相加
    if(n%2 == 1)
        ans = ans*a%m;
    return (int )ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(vis, 0, sizeof vis);
        for(int i = 0;i < n;i++)
        {
            scanf("%s",pic[i]);
        }
        int cnt = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(vis[i][j] == 0 && pic[i][j] == 'Y')
                {
                    vis[i][j] = 1;
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",pow_mod(2,cnt-1,1000000007));
    }
    return 0;
}
