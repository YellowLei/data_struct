#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int a[1500][4]; //用来存各个ip的四个字段的int值

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 1;t <= T;t++)
    {

        int n,m;
        vector<long long> vec;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for(int i = 1;i <= n + m;i++)
        {
            char ip[20];
            scanf("%s",ip);
            int k = 0;
            //将字符串的ip地址转化成4个整数存储
            for(int j = 0;ip[j];j++)
            {
                if(ip[j] == '.')
                    k++;
                else a[i][k] = a[i][k] * 10 + (ip[j] - '0');
            }
        }
        printf("Case #%d:\n",t);
        for(int i = 1;i <= m;i++)   //m个子网掩码
        {
            for(int j = 1;j <= n;j++)   //n个ip地址
            {
                long long sum = 0;
                for(int k = 0;k < 4;k++)
                {
                    //计算ip与子网掩码要与后的结果
                    sum = sum * 1000 + (a[j][k] & a[i + n][k]);
                }
                vec.push_back(sum);
            }
            sort(vec.begin(),vec.end());//排序，是unique的前提
            //剔除字符原理是，看当前字符与他前一个字符是否相同，如果相同就剔除当前字符，
            //如果不同就跳转到下一个字符。所以在求一个字符串的字符集的时候要先把字符串排个序
            //再调用上面两个函数剔除重复字符，获取字符集。
            int ans = unique(vec.begin(),vec.end()) - vec.begin();//unique去除链表里的重复项
            printf("%d\n",ans);
            vec.clear();
        }
    }
    return 0;
}
