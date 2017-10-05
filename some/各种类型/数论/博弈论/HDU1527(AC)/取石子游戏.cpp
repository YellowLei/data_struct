#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;

int main()
{
    int a,b;
    double x=(1+sqrt(5.0))/2;
    while(~scanf("%d%d",&a,&b))
    {
        if(a>b)
        {
            a=a^b;
            b=a^b;
            a=b^a;
        }
        int n=b-a;
        if(a==(int)(x*n))
            printf("0\n");
        else printf("1\n");
    }
    return 0;
}
