#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1010;
int a[maxn][maxn];
int inf = 999999;

int main()
{
    int T;
    scanf("%d",&T);
    int n,m,t1,t2;
    while(T--)
    {
        for(int i = 0;i < maxn;i++)
        {
            for(int j = 0;j < maxn;j++)
            {
                if(i == j)
                    a[i][j] = inf;
                else    a[i][j] = 0;
            }
        }
        int cnt = 0;
        int live = 1;
        scanf("%d",&n);
        while(n--)
        {
            cnt++;
            scanf("%d%d",&m,&t1);
            m--;
            while(m--)
            {
                scanf("%d",&t2);
                if(a[t1][t2] == 0 || a[t1][t2] == cnt)
                {
                    a[t1][t2] = cnt;
                    t1 = t2;
                }
                else    live = 0;
            }
        }
        if(live == 1)
            printf("Good Job!\n");
        else printf("Boom!\n");
    }
    return 0;
}
