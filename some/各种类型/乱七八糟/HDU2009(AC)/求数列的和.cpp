#include<stdio.h>
#include<math.h>
int main()
{
    int m,n;
    double result;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        result=0;
        double t=n;
        while(m--)
        {
             result+=t;
             t=sqrt(t);
        }
        printf("%.2lf\n",result);
    }
    return 0;
}
