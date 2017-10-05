//HUD 3127
//看博客后写的
//思路：这道题布条的总大小即为容量，而且每种剪法的小布条都有价格，很明显的背包题，
//而且由于每种减法可以多次使用，这就构成了一个完全背包，由于布条有长宽，所以使用二维数组。
//要注意的是小布条的长宽并不是固定的，可以旋转，所以剪法有两种，得出两个状态方程
//
//方程1：dp[i][j] = max(dp[i][j],max((dp[i-a[k].x][j]+dp[a[k].x][j-a[k].y]),(dp[i][j-a[k].y]+dp[i-a[k].x][a[k].y]))+a[k].v);
//
//方程2：dp[i][j] = max(dp[i][j],max((dp[i-a[k].y][j]+dp[a[k].y][j-a[k].x]),(dp[i][j-a[k].x]+dp[i-a[k].y][a[k].x]))+a[k].v);
//
//以方程1为例
//
//要注意的是，大布条剪去小布条后剩下的布不一定是矩形，这种情况下剩下的布条可以分成两个矩形，所以总价值就是这三个矩形之和，
//而剩下的矩形又可以看做心的大矩形，由此循环得到
//
//max((dp[i-a[k].x][j]+dp[a[k].x][j-a[k].y]),(dp[i][j-a[k].y]+dp[i-a[k].x][a[k].y]]))+a[k].v
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x[15],y[15],c[15],f[1005][1005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int X,Y,n;
        memset(f,0,sizeof(f));
        scanf("%d%d%d",&n,&X,&Y);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&c[i]);
        }
        for(int i=0;i<=X;i++)
        {
            for(int j=0;j<=Y;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(i>=x[k]&&j>=y[k])//第一种剪法
                    {
                        f[i][j]=max(f[i][j],max(f[i][j-y[k]]+f[i-x[k]][y[k]],f[i-x[k]][j]+f[x[k]][j-y[k]])+c[k]);
                    }
                    if(i>=y[k]&&j>=x[k])//第二种剪法
                    {
                        f[i][j]=max(f[i][j],max(f[i-y[k]][j]+f[y[k]][j-x[k]],f[i][j-x[k]]+f[i-y[k]][x[k]])+c[k]);
                    }
                }
            }
        }
        printf("%d\n",f[X][Y]);
    }
    return 0;
}
