#include<stdio.h>
int main()
{
    int n,i,t,min;
    int a[100];
    while(scanf("%d",&n)!=EOF)
    {
        min=0;
        if(n!=0)
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                if(a[i]<a[min])min=i;
            }
            if(min!=0)
            {
            t=a[0];
            a[0]=a[min];
            a[min]=t;
            }
            for(i=0;i<n-1;i++)
                printf("%d ",a[i]);
            printf("%d",a[n-1]);
            printf("\n");
        }

    }
    return 0;
}
