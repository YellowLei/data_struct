/**
我们可以设置两个指针，一个指向第一个好人，一个指向最后一个好人。两个指针之间肯定都是好人。
如果将要剔除的下标在这两个指针内，那么肯定非法。那么现在的问题在于更新这两个指针。
    两指针分别设为head和tail，即将出队的下标记为pop。pop=(m-1)%len（len表示当前环长度）。
    那么pop+1为新环的第一个人（标号0），pop+2为第二个人（标号1）。
    以此类推，我们便能把所有剩下的人重新标号。

    让我们来看下当前标号为x的人，在重标号后的x'是多少。
    首先我们计算出他与pop+1的间距,显然式子是这样的：d=(x-(pop+1)%len+len)%len
    （(pop+1)%len是pop后一个人的下标），然后 x'=d%(len-1)。
    所以最后x'= ((x-(pop+1)%len+len)%len)%(len-1)。用这个式子我们便能更新head和tail了。
*/
#include <iostream>
#include <cstdio>

int f[14];

void get_f()
{
    int i,j,k,pop,head,tail;
    for(i = 1;i <= 13;i++)//有i个好人，i个坏人
    {
        for(j = i + 1;;j++) //每一次剔除第j个人
        {
            for(k = 2 * i,head = 0,tail = i - 1;k >= i;k--)
            {
                pop = (j - 1) % k;//要剔除的人的位置
                if(pop >= head && pop <= tail)//剔除的人在违法位置则退出，这个j不符合
                    break;
                head = ((head - (pop + 1) % k + k) % k) % (k-1);//重标记后更新head
                tail = ((tail - (pop + 1) % k + k) % k) % (k-1);//tail相同
            }
            if(i == k)
                break;
        }
        f[i] = j;
    }
}
using namespace std;

int main()
{
    int n;
    get_f();
    while(scanf("%d",&n),n)
    {
        printf("%d\n",f[n]);
    }
    return 0;
}
