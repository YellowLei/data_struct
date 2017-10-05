#include <iostream>
#include <cstdio>

using namespace std;

struct City
{
    int distance;
    int buy;
    int sell;
}city[200005];

struct Quene
{
    int number;
    int value;
}que[200005];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,c;
        scanf("%d%d",&n,&c);
        //以1号点为起点，n+1号点为终点，0号点的距离置0是为了起点不用单独拿出来讨论
        city[0].distance = city[1].distance = 0;
        for(int i = 2;i <= n + 1;i++)
        {
            scanf("%d",&city[i].distance);
        }
        for(int i = 1;i <= n + 1;i++)
        {
            scanf("%d%d",&city[i].buy,&city[i].sell);
        }
        long long ans = 0;//记录花费
        int sum = 0;//存的当前口袋里的糖果总量
        int head = 0;//队头前一个 ，队列是从hend+1到endd的
        int endd = 0;//队尾
        for(int i = 1;i <= n+1;i++)
        {
            int dis = city[i].distance - city[i - 1].distance;
            sum -= dis;
            //先从对头元素开始吃
            while(dis != 0)
            {
                if(que[head + 1].number < dis)
                {
                    dis -= que[head + 1].number;
                    head++;
                }
                else
                {
                    que[head + 1].number -= dis;
                    dis = 0;
                }
            }
            //将口袋里价值低于当前城市出售价格的更新为当前的出售价格
            for(int j = head + 1;j <= endd;j++)
            {
                if(que[j].value < city[i].sell)
                    que[j].value = city[i].sell;
            }
            //将口袋里价值高于当前点购买价格的糖果按它们最高价值卖掉
            while(endd > head && que[endd].value > city[i].buy)
            {
                ans -= (long long)que[endd].value * que[endd].number;
                sum -= que[endd].number;
                endd--;//出队
            }
            //离开前，将口袋充满
            if(sum != c)
            {
                endd++;
                que[endd].number = c - sum;
                que[endd].value = city[i].buy;
                ans += (long long)que[endd].number * que[endd].value;
                sum = c;
            }
        }
        //将最后剩下的按照他们的最高价值卖掉
        while(head != endd)
        {
            ans -= (long long)que[head + 1].number * que[head + 1].value;
            head++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
