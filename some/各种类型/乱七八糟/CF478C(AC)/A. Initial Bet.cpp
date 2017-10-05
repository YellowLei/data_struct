#include<stdio.h>
int main()
{
    int a1,a2,a3,a4,a5,sum;
    double b;
    while(scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5)!=EOF)
    {
        sum=a1+a2+a3+a4+a5;
        b=(double)sum/5;
        if((b-sum/5)!=0||(int)b==0)
            printf("-1\n");
        else
            printf("%d\n",(int)b);
    }
    return 0;
}
