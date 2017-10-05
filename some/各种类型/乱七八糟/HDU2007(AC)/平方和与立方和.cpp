#include<stdio.h>
int main()
{
    int m,n,x,y,t;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        x=y=0;
        if(m>n)
        {
            t=m;
            m=n;
            n=t;
        }
        while(m<=n)
        {
            if(m%2==0)
                x+=m*m;
            else  y+=m*m*m;
            m++;
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
