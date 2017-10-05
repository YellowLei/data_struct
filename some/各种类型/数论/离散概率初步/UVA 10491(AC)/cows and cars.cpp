#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        double ans = (a*b+b*(b-1))*1.0/((a+b-c-1)*(a+b));
        printf("%.5f\n",ans);
    }
    return 0;
}
