#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;

int sg[1005],f[12],vis[1005];
void getsg(int n)
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(j=1;f[j]<=i;j++)
        {
            vis[sg[i-f[j]]]=1;
        }
        for(j=0;j<=n;j++)
        {
            if(vis[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}

int main()
{
    int N;
    f[1]=1;
    for(int i=2;i<=11;i++)
    {
        f[i]=2*f[i-1];
    }
    getsg(1000);
    //for(int i=1;i<=100;i++)
    //    printf("%d==%d\n",i,sg[i]);
    while(~scanf("%d",&N))
    {
        if(sg[N]==0)
            printf("Cici\n");//必败
        else printf("Kiki\n");
    }
    return 0;
}

/*
//博客上的，速度较慢
//应该是个巴什博弈吧，首先3是个必败的状态，任何一个不是3的倍数的（>3）都可以经过减1或减2变成3的倍数，
//而1和2都是2的倍数，所以如果把对方控制成三的倍数那么必赢，也就是说谁先抢到不是三的倍数谁赢
//  （如果说错了大牛们指教）
//如果不想证直接自己写几个必胜必败状态就ok了
//必赢 1 2 4 5 7 8 10 11 16 32
//必输 3  6  9  12

#include<stdio.h>
int main ()
{
   int n;
   while(~scanf("%d",&n))
   {
      if(n%3)
      printf("Kiki\n");
      else
      printf("Cici\n");
    }
    return 0;
}
*/
