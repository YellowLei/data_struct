#include<stdio.h>
int main()
{
    int n,m,i;
    while(scanf("%d%d",&n,&m)!=EOF)
        {
            for(i=1;i<=n-m;i+=m)
            {
                printf("%d ",2*i+m-1);
            }
            printf("%d\n",i+n);
        }
    return 0;
}
