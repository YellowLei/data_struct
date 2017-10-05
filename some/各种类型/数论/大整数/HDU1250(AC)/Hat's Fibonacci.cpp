#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 100000000;
int a[10000][260];//每个元素可以存储8位数字，所以2005位可以用260个数组元素存储

int main()
{
    a[1][0] = 1;
    a[2][0] = 1;
    a[3][0] = 1;
    a[4][0] = 1;
    for(int i = 5;i < 10000;i++)
    {
        for(int j = 0;j < 260;j++)
        {
            a[i][j] += a[i-1][j] + a[i-2][j] + a[i-3][j] + a[i-4][j];
            if(a[i][j] > mod)//每八位考虑进位
            {
                a[i][j+1] += a[i][j]/mod;
                a[i][j] %= mod;
            }
        }
    }
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        for(i = 259;i >= 0;i--)
        {
            if(a[n][i] != 0) //不输出高位的0
                break;
        }
        printf("%d",a[n][i]);
        for(i = i - 1;i >= 0;i--)
            printf("%08d",a[n][i]);//每个元素存储了八位数字，所以控制输出位数为8，左边补0
        printf("\n");
    }
    return 0;
}
