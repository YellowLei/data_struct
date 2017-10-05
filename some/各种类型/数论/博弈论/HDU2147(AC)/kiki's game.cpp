#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&(m!=0||n!=0))
    {
        //要保证kiki在一个方向走的步数是奇数才能赢，行和列分别要走n-1步和m-1步，
        //所以n和m中至少有一个要是偶数
        if(n%2==0||m%2==0)
            printf("Wonderful!\n");
        else printf("What a pity!\n");
    }
    return 0;
}
