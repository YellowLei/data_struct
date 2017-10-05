#include<stdio.h>
#include<math.h>
int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x==0&&y==0) continue;
        int i,a,n=0;
        for(int i=x;i<=y;i++)
        {
            a=x*x+x+41;
            for(i=2;i<sqrt(a);i++) //若2到根号n之间所有整数去除，均无法整除，则n为素数
            {
                if(a%i==0)
                    n=1;
                break;
            }
        }
        if(n==0)
            printf("OK\n");
        else
            printf("Sorry\n");
    }
    return 0;
}
