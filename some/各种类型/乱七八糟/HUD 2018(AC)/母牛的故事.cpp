#include<iostream>
#include<cstdio>

using namespace std;

int f(int n)
{
    if(n<=4)
        return n;
    return f(n-1)+f(n-3);
}
int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        if(n<=4)
            printf("%d\n",n);
        else
            printf("%d\n",f(n));
    }
    return 0;
}
