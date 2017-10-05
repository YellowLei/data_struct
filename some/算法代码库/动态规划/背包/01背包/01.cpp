//http://blog.csdn.net/crayondeng/article/details/15784093


#include <iostream>
using namespace std;

//物品数据结构
typedef struct commodity
{
    int value;  //价值
    int weight; //重量
}commodity;

const int N = 3;  //物品个数
const int W = 50; //背包的容量

//初始物品信息
commodity goods[N+1]={{0,0},{60,10},{100,20},{120,30}};
int select[N+1][W+1];

int max_value()
{
    //初始没有物品时候，背包的价值为0
    for(int w=1;w<=W;++w)
        select[0][w] = 0;
    for(int i=1;i<=N;++i)
    {
        select[i][0] = 0;  //背包容量为0时，最大价值为0
           for(int w=1;w<=W;++w)
           {
               if(goods[i].weight <= w)  //当前物品i的重量小于等于w，进行选择
               {
                   if( (goods[i].value + select[i-1][w-goods[i].weight]) > select[i-1][w])
                    select[i][w] = goods[i].value + select[i-1][w-goods[i].weight];
                   else
                    select[i][w] = select[i-1][w];
               }
               else //当前物品i的重量大于w，不选择
                 select[i][w] = select[i-1][w];
           }
    }
    return select[N][W];  //最终求得最大值
}

int main()
{
    int maxvalue = max_value();
    cout<<"The max value is: ";
    cout<<maxvalue<<endl;
    int remainspace = W;

    //输出所选择的物品列表：
    //这是一个反向推导出最优解的过程。输出的物品编号也就是倒序的，可以用一个栈保存下来，然后再输出
    for(int i=N; i>=1; i--)
    {
        if (remainspace >= goods[i].weight)
        {
             if ((select[i][remainspace]-select[i-1][remainspace-goods[i].weight]==goods[i].value))
             {
                 cout << "item " << i << " is selected!" << endl;
                 remainspace = remainspace - goods[i].weight;//如果第i个物品被选择，那么背包剩余容量将减去第i个物品的重量 ;
             }
        }
    }
    return 0;
}



//简化后的代码

//获取两个数的大者
int getMax(int a,int b)
{
    return a>=b?a:b;
}
int Backpack()
{
    //初始化二维表中的第一行
    for(int k=0; k<=W; k++)
        select[0][k] = 0;
    //初始化二维表中的第一列
    for(int k=0; k<=N; k++)
        select[k][0] = 0;

    //逐行进行填表
    for(int i=1; i<=N; i++) //物品编号从 1~N
    {
        for(int j=1; j<=W; j++) //背包容量从 1~W
        {
            select[i][j] = select[i-1][j];
            if(goods[i].weight <= j)
            {
                select[i][j] = getMax(select[i][j],select[i-1][j-goods[i].weight]+goods[i].value);
            }
        }
    }
    return select[N][W];
}



//其他模板
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int weight[1005],value[1005],f[1005];
    int n,v,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&v);
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
            scanf("%d",&value[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&weight[i]);
        //f(i)里一直存放着容积为i时最大的价值
        for(int i=1;i<=n;i++)
        {
            for(int j=v;j>=weight[i];j--)
            {
                f[j]=max(f[j],f[j-weight[i]]+value[i]);
            }
        }
        printf("%d\n",f[v]);
    }
    return 0;
}

//如果要求恰好装满背包，那么在初始化时除了f[0]为0其它f[1..V]均设为-∞，
//这样就可以保证最终得到的f[N]是一种恰好装满背包的最优解。
//如果并没有要求必须把背包装满，而是只希望价格尽量大，初始化时应该将f[0..V]全部设为0。
//
//为什么呢？可以这样理解：初始化的f数组事实上就是在没有任何物品可以放入背包时的合法状态。
//如果要求背包恰好装满，那么此时只有容量为0的背包可能被价值为0的nothing“恰好装满”，
//其它容量的背包均没有合法的解，属于未定义的状态，它们的值就都应该是-∞了。如果背包并非必须被装满，
//那么任何容量的背包都有一个合法解“什么都不装”，这个解的价值为0，所以初始时状态的值也就全部为0了
