#include <iostream>
#include <cstdio>

using namespace std;

//思路:取模的题目结果一般都有规律.此题会误以为周期就是7,但是,这题两个数相加后在对7取模,
//所以就有7*7=49种情况,即,周期为:49;
int main()
{
    int a,b,n;
    int f,f1,f2;
    while(scanf("%d%d%d",&a,&b,&n)&&(a != 0 && b != 0 && n != 0))
    {
        f1 = f2 = 1;
        f = 1;
        int tmp = n % 49;
        tmp = tmp == 0 ? 50 : tmp;
        for(int i = 3;i <= tmp;i++)
        {
            f = (a * f1 + b * f2) % 7;
            f2 = f1;
            f1 = f;
        }
        printf("%d\n",f);
    }
    return 0;
}
