#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a1,a2,a3,a4,a5,a6,L;
    while(scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6)!=EOF)
    {
        L=a1+a2+a3;
        cout<<L*L-a1*a1-a3*a3-a5*a5<<endl;
    }
    return 0;
}
