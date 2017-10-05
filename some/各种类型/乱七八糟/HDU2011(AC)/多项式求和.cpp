#include<stdio.h>
#include<math.h>
int main()
{
    int i,n,j,m;
    double sum;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        for(i=1,sum=0;i<=n;i++)
        {
            j=pow(-1,(i+1));
            sum+=j*(1.0/i);
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
