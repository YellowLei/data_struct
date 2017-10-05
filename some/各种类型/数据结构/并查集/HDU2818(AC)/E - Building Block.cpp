#include<iostream>
#include<cstdio>

using namespace std;

const int MAX=30005;
int pre[MAX],num[MAX],under[MAX];//num[X]：X是集合代表,某个堆(集合)中Piles的总数
                            //under[i]: 编号为i的Pile下面有多少个Piles (一边进行查找，一边更新)

int findFather(int x)
{
    int tmp;
    if(pre[x]!=x)
    {
        tmp=findFather(pre[x]);//递归过程自底向上自动更新under[],递归基础：下面的under[X] = num[Y]
        under[x]+=under[pre[x]];//现在x下面的方块数是它所有祖先下面方块的总和
        pre[x]=tmp;
    }
    return pre[x];
}
void join(int x,int y)
{
    int fx=findFather(x);
    int fy=findFather(y);
    if(fx!=fy)
    {
        under[fx]=num[fy];//X放在Y上,X是当前堆(集合)中最底部的，直接更新under[]
        num[fy]+=num[fx]; //直接更新Y这堆(集合)的高度(总共多少个Piles)
        pre[fx]=fy;//合并,注意是X加到Y上，不同于一般的并查集的father[Y]=X
    }
}
int main()
{
    int N;
    while(~scanf("%d",&N))
    {
        char oper[5];
        int m,n;
        for(int i=0;i<=MAX;i++)
        {
            pre[i]=i;
            num[i]=1;
            under[i]=0;
        }
        for(int i=1;i<=N;i++)
        {
            scanf("%s",oper);
            if(oper[0]=='M')
            {
                scanf("%d%d",&m,&n);
                join(m,n);
            }
            else
            {
                scanf("%d",&m);
                findFather(m);      //可能在进行C操作时m的并集中有新元素加入，所以要重新算under
                printf("%d\n",under[m]);
            }
        }
    }
    return 0;
}
