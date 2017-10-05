#include<iostream>
#include<cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)&&(m!=0||n!=0))
    {
        if(n>m)
            swap(m,n);
        bool flag=true;
        while(1)
        {
            //谁先遇到m/n>1或m==n，谁赢
            //如m/n>1.  那么 那个人肯定知道m&n,n是必胜态还是必败态。
            //如果是必败态，先手将m,n变成m%n,n,那么先手肯定赢。如果是必胜态，先手将m,n变成m%n+n,n.
            //那么对手只有将这两个数变成m%n,n,先手获胜。
            if(m/n>1||m==n)
                break;
            m=m-n;
            swap(m,n);
            flag=!flag;
        }
        if(flag==true)
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
