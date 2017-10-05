#include<iostream>
#include<cstdio>

using namespace std;

int a,b,d;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);

}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        d=gcd(a,b);
        if(d!=1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
