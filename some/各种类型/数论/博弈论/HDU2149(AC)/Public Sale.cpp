#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
        if(m<=n)
        {
            for(int i=m;i<n;i++)
                printf("%d ",i);
            printf("%d\n",n);
        }
        else
        {
            int k=m%(n+1);
            if(k==0)
                printf("none\n");
            else printf("%d\n",k);
        }

    }
    return 0;
}
