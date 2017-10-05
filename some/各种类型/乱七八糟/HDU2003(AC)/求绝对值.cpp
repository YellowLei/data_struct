#include<stdio.h>
int main()
{
    double a;
    while(scanf("%lf",&a)!=EOF)
        printf("%.2lf\n",a>0?a:-a);
    return 0;
}
