#include<cstdio>

int main()
{
    __int64 ans[505]={0,1};
    for(int i=2;i<=500;i++)
    {
        ans[i]=ans[i-1]+i*(i+1)/2;//i*(I+1)/2是加了一行之后向上的三角形个数，n+n-1+n-2+...+1,底边长为n，n-1的个数
        //加上向下的三角形个数，底边为1的有n-1个，底边为2的有n-3个，n-4...
        int k=i-1;
        while(k>0)
            {
                ans[i]+=k;
                k-=2;
            }
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",ans[n]);
    }
    return 0;
}
