#include<stdio.h>
int main()
{
    int m,n,i;
    int x,y,z;
    while(scanf("%d%d",&m,&n)!=EOF,m>=100,n<=999,m<=n)
    {
        i=0;
        while(m<=n)
        {
            x=m/100;
            y=(m%100)/10;
            z=m%10;
            if(m==x*x*x+y*y*y+z*z*z)
                {
                    if(i>0)
                        printf(" %d",m);
                    else printf("%d",m);
                    i++;
                }
                m++;
        }
        if(i==0)
            printf("no");
        printf("\n");
    }
    return 0;
}
