#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int T,m,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        //sg==0,先手必败,先手拿n个，后手只需拿m+1-n个，最后的一定的后手拿
        //sg！=0，先手只需先拿走n%(m+1)个，
        if(n%(m+1)==0)
            printf("second\n");
        else
            printf("first\n");
    }
    return 0;
}
