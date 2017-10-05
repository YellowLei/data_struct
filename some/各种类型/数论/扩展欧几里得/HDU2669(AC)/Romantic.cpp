#include<iostream>
#include<cstdio>

using namespace std;

int a,b,d,x,y;

//扩展欧几里得算法，d是最大公因数，x，y是满足ax+by=d的两个整数
void gcd(int a,int b,int &d,int&x,int&y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
int main()
{
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        gcd(a,b,d,x,y);
//设a，b，c为任意整数，g=gcd(a,b),方程ax+by=g的一组解是(x0,y0),
//则当c是g的整数倍时ax+by=c的一组解是(x0c/g,y0c/g);当c不是g的倍数时无整数解
        if(d!=1)
            printf("sorry\n");
        else
        {
            while(x<0)
            {
                x+=b;
                y-=a;
            }
            printf("%d %d\n",x,y);
        }

    }
    return 0;
}
