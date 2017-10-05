////求解1到n的全部素数
//
////方法一：一般,时间复杂度为O(n*sqrt(n))
//for(int i=1;i<=n;i++)
//{
//    int k=1;
//    for(int j=2;j<=sqrt(i);j++)
//    {
//        if(i%j==0)
//            k=0;
//    }
//    if(k==1)
//        printf("%d ",i);
//}

//方法二：

#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    const int n = 100;
    bool vis[101];
    int m = sqrt(n + 0.5);
    memset(vis,0, sizeof(vis));//初始化全部是素数
    //对于不超过n的每个非负整数p，删除2p，3p...，当处理完所有数后，还没有被删除的就是素数
    for(int i = 2;i <= m;i++)
    {
        if(!vis[i])
        {
            for(int j = i*i;j <= n;j+=i)
            {
                vis[j] = 1;
            }
        }
    }
    for(int i = 2; i <= n; i ++)
    {
        if(!vis[i]) cout << i << " ";
    }
    return 0;

}
