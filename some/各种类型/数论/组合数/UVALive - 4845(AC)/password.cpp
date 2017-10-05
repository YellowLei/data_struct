//递推法
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char G[2][6][5],ans[6];//G存表，ans存结果
char Select[5][6];//按字母序存每一列可能出现的字母
int cnt[5],he[5];//cnt存每一列满足的字母的数量，he存后缀可能出现的情况数
char vis[2][26];//存每一列的是否出现的字母，vis[i][j]==1表示第j个字母出现过

int main()
{
    int T,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        for(int i = 0;i < 2;i++)
        {
            for(int j = 0;j < 6;j++)
            {
                scanf("%s",G[i][j]);
            }
        }

        //先算出后缀积，和每一列可能出现的字母的二维表
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i < 5;i++)//i表示列数
        {
            memset(vis,false,sizeof(vis));
            for(int j = 0;j < 2;j++)//两张表
            {
                for(int m = 0;m < 6;m++)//行
                    vis[j][G[j][m][i] - 'A'] = 1;
            }
            //按字母序遍历
            for(int j = 0;j < 26;j++)
            {
                if(vis[0][j] && vis[1][j])
                    Select[i][++cnt[i]] = j + 'A';
            }
        }
        //长度为5的后缀没有，所以
        he[5] = 1;
        for(int i = 4;i >= 0;i--)
        {
            he[i] = he[i + 1] * cnt[i];
        }
        if(k > he[0])
        {
            printf("NO\n");
            continue;
        }
        k--;//程序中从0开始计算
        for(int i = 0;i < 5;i++)
        {
            int t = k / he[i + 1];  //判断第i个字母选第几个
            ans[i] = Select[i][t + 1];
            k %= he[i+1];
        }
        ans[5] = '\0';
        printf("%s\n",ans);
    }
    return 0;
}


/*
//暴力搜索
#include <iostream>
#include <cstdio>
#include <cstring>

int k,cnt;
char G[2][6][5],ans[6];//G数组用来存两张表，ans用来存结果

using namespace std;

bool dfs(int col)
{
    //col==5表示找到一组字典序的序列
    if(col == 5)
    {
        if(++cnt == k)
        {
            ans[col] = '\0';//输出结束的标志
            printf("%s\n",ans);
            return true;
        }
        return false;
    }

    bool vis[2][26];
    memset(vis,false,sizeof(vis));
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 6;j++)
            vis[i][G[i][j][col] - 'A'] = 1;
    }
    //按字典序的
    for(int i = 0;i < 26;i++)
    {
        if(vis[0][i] && vis[1][i])
        {
            ans[col] = i + 'A';
            if(dfs(col + 1))//说明在dfs(col + 1)时找到结果了
                return true;
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        for(int i = 0;i < 2;i++)
        {
            for(int j = 0;j < 6;j++)
            {
                scanf("%s",G[i][j]);
            }
        }
        cnt = 0;
        if(!dfs(0))
            printf("NO\n");
    }
    return 0;
}
*/
