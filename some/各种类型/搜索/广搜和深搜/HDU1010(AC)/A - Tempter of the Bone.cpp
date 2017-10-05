#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=10;
int n,m,t,sx,sy,dx,dy;;
char s[maxn][maxn];
int flag,a[4][2]={-1,0,1,0,0,1,0,-1},visited[maxn][maxn];

void Dfs(int x,int y,int ncount)
{
    int i,tx,ty;
    //狗到门前结束
    if(x==dx&&y==dy)
    {
        if(ncount==t)
            flag=1;
        return;
    }
    //狗无法到门前 结束
    if(ncount>=t)
        return;
    if(s[x][y]!='X')
    {
   //     printf("44444444\n");
        for(i=0;i<4;i++)
        {
            tx=x+a[i][0];
            ty=y+a[i][1];
            if(s[tx][ty]!='X'&&tx>0&&tx<=n&&ty>0&&ty<=m&&!visited[tx][ty])//注意边界
            {
                visited[tx][ty]=1;
                Dfs(tx,ty,ncount+1);
                visited[tx][ty]=0;
                if(flag)        //在找到了目标之后，就不需要再找！
                    return;
            }
        }
    }

}
int main()
{

    while(scanf("%d%d%d",&n,&m,&t),m+n+t)
    {
        int ncount;
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%c",&s[i][j]);
                if(s[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                if(s[i][j]=='D')
                {
                    dx=i;
                    dy=j;
                }
            }
            getchar();
        }
    //    printf("111111111\n");
        memset(visited,0,sizeof(visited));
        //剪枝
        //1.可能的最短路径大于t则一定不可能到
		//2.狗到门的时间奇偶性与门打开的时间的奇偶性不同一定无法到达
        if(abs(sx-dx)+abs(sy-dy)>t||(sx+sy+dx+dy+t)%2==1)
        {
            printf("NO\n");
            continue;
        }
    //    printf("222222222\n");
        visited[sx][sy]=1;
        flag=0;
        ncount=0;
        Dfs(sx,sy,ncount);
    //    printf("333333333\n");
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
