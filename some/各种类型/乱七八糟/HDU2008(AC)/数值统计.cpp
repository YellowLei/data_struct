#include<stdio.h>
int main()
{
    int n,x,y,z;
    double t;
    while(scanf("%d",&n)!=EOF,n!=0)
    {
        x=y=z=0;
        if(n!=0&&n<100)
        {
            while(n--)
            {
                scanf("%lf",&t);
                if(t<0)
                   x++;
                else if(t==0)
                    y++;
                else if(t>0)
                    z++;
            }
            printf("%d %d %d\n",x,y,z);
        }
    }
    return 0;
}
