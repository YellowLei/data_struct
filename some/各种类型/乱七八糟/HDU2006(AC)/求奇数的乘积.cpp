#include<stdio.h>
int main()
{
    int n,t,result;
    while(scanf("%d",&n)!=EOF)
    {
        result=1;
        while(n--)
        {
            scanf("%d",&t);
            if(t%2!=0)
                result*=t;
        }
        printf("%d\n",result);
    }
    return 0;
}
