#include<stdio.h>
int main()
{
    int n,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=1;
        while(n>1)
        {
            sum=(sum+1)*2;
            n--;
        }
        printf("%d\n",sum);
    }
    return 0;
}
