#include<stdio.h>
#include<string.h>

bool g[110][310]; //邻接矩阵，true代表有边相连，g[i][j]表示学生j选了i课
bool visit[310];  //记录学生是否被搜索过
bool flag;        //判断是否没门课都有人选，flag为false时表示有课没人选
int match[310];   //记录与学生匹配的课的编号
int p,n;          //二分图中左边、右边集合中顶点的数目(课数和学生数)

// 匈牙利算法
bool dfs(int u)
{
	for (int i = 1; i <= n; ++i)
	{
		if (g[u][i] && !visit[i])   //如果节点i与u相邻并且未被查找过
		{
			visit[i] = true;   //标记i为已查找过
			if (match[i] == -1 || dfs(match[i]))//如果i未在前一个匹配M中||i在匹配M中，但是从与i相邻的节点出发可以有增广路径
			{
				match[i] = u;  //记录查找成功记录，更新匹配M（即“取反”）
				return true;   //返回查找成功
			}
		}
	}
	return false;
}

int main()
{
    int i,j,k,t,v,ans;
    scanf("%d",&t);
    while (t--)
    {
          scanf("%d %d", &p, &n);
          //初始化，全部没有匹配
          for (i = 1; i <= p; i++)
		  {
              for (j = 1; j <= n; j++)
                  g[i][j] = false;
		  }
          for (i = 1; i <= n; i++)
              match[i] = -1;

          flag = true;

          for (i = 1; i <= p; i++)
          {
              scanf("%d",&k);
              if (k == 0)
                 flag = false;
              while (k--)
              {
                    scanf("%d",&v);
                    g[i][v]  = true;//学生v选择了课i
              }
          }

          if (flag)//如果有门课没人选肯定无法满足
          {
               ans = 0;
               for (i = 1; i <= p; i++)
               {
                   memset(visit,false,sizeof(visit));   //清空上次搜索时的标记
                   if( dfs(i) )    //从节点i尝试扩展
					   ans++;
               }
               if (ans == p)    //最大匹配等于课程数
				   puts("YES");
               else
				   puts("NO");
          }
          else
			  puts("NO");
    }

    return 0;
}
