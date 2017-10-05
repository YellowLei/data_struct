#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int m,n;
    int a[110];
    while(~scanf("%d%d",&m,&n),m+n)
    {
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(int i=m-1;i>=0;i--)
        {
            if(a[i]>n)
                a[i+1]=a[i];
            else
                if(a[i]<=n)
                {
                    a[i+1]=n;
                    break;
                }
        }
        for(int i=0;i<m;i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[m]);
    }
    return 0;
}
