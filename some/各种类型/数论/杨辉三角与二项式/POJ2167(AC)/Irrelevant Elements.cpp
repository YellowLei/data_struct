//杨辉三角
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100005;

int fac[100][2];//m分解成唯一分解式，fac[i][0]记录素数，fac[i][1]记录素数的指数
int fac_c[100];
int a[N];

//分解m
void factor(int m)
{
    int&num = fac[0][0];//表头，存放分解后总的素数个数
    num = 0;
    for(int i = 2;i*i <= m;i++)
    {
        if(m%i == 0)
        {
            fac[++num][0] = i;
            fac[num][1] = 0;
        }
        while(m%i == 0)//将i除干净
        {
            fac[num][1]++;
            m /= i;
        }
    }
    //质数只能分解成它本身，指数为1
    //如果分解到最后m仍然大于1,说明它是一个素数。注意：如果只是判断素因子有哪些，可以没有此处判断，否则必须有此步
    if(m > 1)
    {
        fac[++num][0] = m;
        fac[num][1] = 1;
    }
}

//按照递推公式来计算第j项，检查唯一分解式的指数
//(n-1)/1 * (n-2)/2 * (n-3)/3 ...从1/n 开始算，算的已存入fac_c中，接下来只需算(n-2)/2....
bool check(int n,int j)
{
    int num = fac[0][0];
    int a = n - j;//其实是((n-1)-(j-1))化简后的结果
    int b = j;
    for(int i = 1;i <= num;i++)
    {
        int p = fac[i][0];
        int&q = fac_c[i];
        //为了提高效率，只用检验m的分解式中的素因数即可
        while(a % p == 0)
        {
            a /= p;
            q++;
        }
        while(b % p ==0)
        {
            b /= p;
            q--;
        }
    }
    for(int i = 1;i <= num;i++)
    {
        if(fac[i][1]>fac_c[i])
            return false;
    }
    return true ;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int  cnt = 0;
        factor(m);
        memset(fac_c,0,sizeof(fac_c));
        for(int i = 1;i < n;i++)//直接检查1到n-1项（从0开始）
        {
            if(check(n,i))
                a[cnt++] = i + 1;
        }
        printf("%d\n",cnt);
        for(int i = 0;i < cnt;i++)
        {
            printf("%s%d",i == 0 ? "" : " ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
