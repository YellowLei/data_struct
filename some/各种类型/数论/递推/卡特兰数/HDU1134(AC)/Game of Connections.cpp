#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 110;
const int mod = 10000;//4位存入

int c[maxn][maxn]={0};

//大整数乘法
//注意进位是不用*n的
void multiply(int a[],int n)
{
    int vis = 0;//进位
    for(int i = 0;i < maxn;i++)
    {
        vis += a[i] * n;
        a[i] = vis % mod;
        vis /= mod;
    }
}

//大整数除法
void divide(int a[],int n)
{
    int vis = 0;//向上请求
    for(int i = maxn-1;i >= 0 ;i--)
    {
        vis = vis * mod + a[i];
        a[i] = vis / n;
        vis %= n;
    }
}

int main()
{
    c[0][0] = 1;
    c[1][0] = 1;
    for(int i = 2;i < maxn;i++)
    {
        memcpy(c[i],c[i-1],maxn*sizeof(int));
        multiply(c[i],4*i-2);
        divide(c[i],i+1);
    }
    int n;
    while(scanf("%d",&n)&&n != -1)
    {
        int i;
        for(i = maxn-1;i >= 0;i--)
            if(c[n][i] != 0) break;
        printf("%d",c[n][i]);
        for(i = i - 1;i >= 0;i--)
            printf("%04d",c[n][i]);
        printf("\n");
    }
    return 0;
}
