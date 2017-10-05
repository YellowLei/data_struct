/**
设f(N,K)返回最后取出的编号

那么f(n,k)进行第一次选后，剩下n-n/k个人，这剩下的人里最后被取出的编号为f(n-n/k,k)记为x;
那么它在前一次队列里的编号则是(x-1)/(k-1)+x   (x-1)/(k-1)是前一次被干掉的
所以f(n,k)=(x-1)/(k-1)+x 其中x=f(n-n/k,k)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int killnum(int n,int k)
{
    if(n == k)
        return n;
    int i = killnum(n - n / k,k);
        return (i - 1) / (k - 1) + i;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        printf("%d\n",killnum(n,k));
    }
    return 0;
}
