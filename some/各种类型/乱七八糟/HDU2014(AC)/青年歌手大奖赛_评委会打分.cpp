#include<stdio.h>
int main()
{
    int n,t,max,min;
    double sum;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>2&&n<=100)
         {
            sum=0;
            max=min=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&t);
                if(i==0)
                    max=min=t;
                if(max<t)max=t;
                if(min>t)min=t;
                sum+=t;
            }
            sum=sum-min-max;
            printf("%.2lf\n",sum/(n-2));
         }
    }
    return 0;
}
