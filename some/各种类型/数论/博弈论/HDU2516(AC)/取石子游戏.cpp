//找规律
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    long long n;
    long long fib[50];
    fib[0]=2;
    fib[1]=3;
    for(int i=2;i<50;i++)
        fib[i]=fib[i-1]+fib[i-2];
    while(scanf("%I64d",&n)&&n)
    {
        bool flag=true;
        for(int i=0;i<50;i++)
        {
            if(n==fib[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            printf("First win\n");
        else printf("Second win\n");
    }
    return 0;
}
