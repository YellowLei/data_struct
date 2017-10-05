//连续打中才会有分
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 10005;

double pow[maxn];

void get_pow(double p,int n)
{
    pow[1] = p;
    for(int i = 2;i <= n;i++)
        pow[i] = pow[i-1] * p;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        double p;
        scanf("%d%lf",&n,&p);
        get_pow(p,n);
        double ans = 0;
        for(int i = 1;i <= n;i++)
            ans += i * pow[n-i+1];
        printf("%.6lf\n",ans);
    }
    return 0;
}
