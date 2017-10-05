#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 500;

char str[maxn];
int a[maxn*2],b[maxn*2],sum[maxn*2];

//将str[]里的数存入数组a[]中
void putin(int a[],char str[])
{
    int len_a,len;
    len_a = strlen(str);
    if(strchr(str,'.') == NULL)//strchr()得到第一个字符出现的地址
        len = len_a;
    else len = strchr(str,'.') - str;//小数点的位置
    for(int i = len - 1,j = maxn;i >= 0;i--,j++)
        a[j] = str[i] - '0';
    for(int i = len +1,j = maxn - 1;i < len_a;i++,j--)
        a[j] = str[i] - '0';
}
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(sum,0,sizeof(sum));

        putin(a,str);
        scanf("%s",str);
        putin(b,str);

        for(int i = 0;i <= 2*maxn;i++)
        {
            sum[i] += a[i] + b[i];
            if(sum[i] >= 10)
            {
                sum[i] -= 10;
                sum[i + 1]++;
            }
        }
        int i,j;
        //不输出前导0
        for(i = maxn * 2;i >= 0;i--)
            if(sum[i] != 0) break;
        for(;i >= 500;i--)
            printf("%d",sum[i]);
        //判断有无小数
        for(j = 0;j < 500;j++)
            if(sum[j] != 0) break;
        if(j != 500)
        {
            printf(".");
            for(i = 499;i >= j;i--)
                printf("%d",sum[i]);
        }
        printf("\n");
    }
    return 0;
}
