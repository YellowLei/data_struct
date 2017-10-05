#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n;
        scanf("%d%d",&n,&m);
        if(n%(m+1)!=0)
            printf("Grass\n");
        else printf("Rabbit\n");
    }
    return 0;
}
