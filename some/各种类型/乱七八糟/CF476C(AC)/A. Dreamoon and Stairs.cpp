#include<stdio.h>
int main()
{
    int m,n,min,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        t=0;
        min=(n+1)/2;
        for(int i=min;i<=n;i++)
        {
            if(i%m==0)
            {
                 printf("%d\n",i);
                 t=1;
                 break;
            }
        }
        if(t==0)
            printf("-1\n");
    }
    return 0;
}
