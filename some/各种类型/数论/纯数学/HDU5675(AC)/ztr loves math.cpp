#include <iostream>
#include <cstdio>

using namespace std;

//思路：
//n=x^2-y^2=(x+y)*(x-y),令a=(x+y),b=(x-y),解得x=(a+b)/2,y=(a-b)/2;因为x和y都是整数，所以a与b同奇数同偶数
//当a与b都是奇数时，n=a*b 必定是奇数，但a！=b，所以n不为1；
//但a与b都是偶数时，n=a*b必定是4的倍数，但a！=b，所以n不为4；
//综上，当n是奇数或4的倍数且不是1和4时n=x^2-y^2有解
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        scanf("%I64d",&n);
        if(n == 1 || n == 4)
        {
            printf("False\n");
            continue;
        }
        else if(n % 2 == 1 || n % 4 == 0)
            {
                printf("True\n");
                continue;
            }
        else printf("False\n");
    }
    return 0;
}
