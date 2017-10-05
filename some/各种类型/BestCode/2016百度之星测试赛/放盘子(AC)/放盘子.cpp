#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

const double PI = 3.1415926;

int main()
{
    int T;
    int n;
    double a,r;
    scanf("%d",&T);
    for(int t = 1;t <= T;t++)
    {
        scanf("%d%lf%lf",&n,&a,&r);
        double x,y,ans;
        x = PI * (n - 2) / (2 * n);
        y = tan(x);
        ans = y * a;
        printf("Case #%d:\n",t);
        if(ans <= r * 2)
            printf("I want to kiss you!\n");
        else printf("Give me a kiss!\n");
    }
    return 0;
}
