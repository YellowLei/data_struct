#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T,f,m,k,tmp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&f,&m,&k);
        int ans = f % m;
        for(int i = 2;i <= k ;i++)
        {
            ans = (2 * ans) % m;
            if(ans == f)
            {
                tmp = i - 1;
                break;
            }
        }
        tmp = k % tmp;
        for(int i = 2;i <= tmp ;i++)
        {
            ans = (2 * ans) % m;
        }
        printf("%d\n",ans);
    }
    return 0;
}
