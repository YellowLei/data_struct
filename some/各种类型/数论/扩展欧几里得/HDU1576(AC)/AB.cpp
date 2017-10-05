#include<iostream>
#include<cstdio>

using namespace std;

int a,b,d,x,y;
void gcd(int a,int b,int & d,int & x,int & y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        gcd(9973,b,d,x,y);
        y=a*y;
        y=(y%9973+9973)%9973;
        printf("%d\n",y);
    }
    return 0;
}
