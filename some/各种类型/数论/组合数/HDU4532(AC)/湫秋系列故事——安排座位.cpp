//组合数+动归
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const LL mod = 1000000007;
const int maxn = 550;

LL a[maxn];         //第i系的人数
LL A[maxn];         //个元素的全排列
LL c[maxn][maxn];   //组合数
LL dp[50][maxn];    //表示前i个系的人排好后有j个位置两侧是同一个系的人的排列方案数。

void Init()
{
    for(int i = 0;i < maxn;i++)
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1;j < i;j++)
        {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }

        A[0] = 1;
        for(int i = 1;i < maxn ;i++)
        {
            A[i] = (A[i-1] * i) % mod;
        }

    }
}

int main()
{
    Init();
    int T;
    scanf("%d",&T);
    for(int t = 1;t <= T;t++)
    {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[1][a[1]-1] = 1;  //就一种
        LL sum = a[1];
        //每次枚举之前一共有j个空位置
        //将当前的a[i]分成k组：c[a[i]-1][k-1]
        //在j个空位置中插入k组中的u组:c[j][u]
        //还剩下k-u组，插入到sum+1-j个空位置
        //注意：j表示一共有j个位置两侧是同一个班级的人
        //一共有sum个人，那么还有sum+1-j位置两侧是不同班级的人
        for(int i = 2;i <= n;i++)
        {
            for(int j = 0;j < sum;j++)
            {
                for(int k = 1;k <= a[i];k++)
                {
                    for(int u = 0;u <= j && u <= k;u++)
                    {
                        //j-u+a[i]-1-(k-1)表示本来有j个空，插入u个后直接减少u个空，但插入的u组会产生新的空(每个系不排列有a[i]-1个空，分成k组又会减少k-1个空)
                        //dp[i][j-u+a[i]-k]+ 表示动归要加上以前的
                        //dp[i-1][j] * c[j][u]  * c[sum+1-j][k-u] * c[a[i]-1][k-1] 新增的情况
                        //dp[i-1][j]表示没插入这一个系时j个空有多少种，c[j][u]在j个空中选u个插入被选中的u个组，c[sum+1-j][k-u]将不是选中的u个组插入到一般的空里
                        dp[i][j-u+a[i]-1-(k-1)] = (dp[i][j-u+a[i]-k] + (((dp[i-1][j] * c[j][u]) % mod * c[sum+1-j][k-u]) % mod * c[a[i]-1][k-1]) % mod) % mod;
                    }
                }
            }
            sum += a[i];
        }
        printf("Case %d: ",t);
        LL ans = dp[n][0];
        for(int i = 1;i <= n;i++)
        {
            ans = (ans * A[a[i]]) % mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
