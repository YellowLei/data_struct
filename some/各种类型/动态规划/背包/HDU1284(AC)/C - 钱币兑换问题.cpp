
//数学方法
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,sum;
    while(~scanf("%d",&n))
    {
        sum=n/3+n/2+1;              //n/3为只有3和1的情况，n/2为只有2和1的情况，1为全部是1的情况
        for(int i=1;i<=n/3;i++)      //接下来算3，2，1都有或只有3，2的情况
            sum+=(n-3*i)/2;
        printf("%d\n",sum);
    }
    return 0;
}


/*
//用完全背包做
#include<stdio.h>
int dp[35000];
int main()
{
    int i,j;
    dp[0]=1;
    for(i=1;i<=3;i++)
        for(j=i;j<=35000;j++)
            dp[j]+=dp[j-i];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",dp[n]);
    }
    return 0;
}
*/
