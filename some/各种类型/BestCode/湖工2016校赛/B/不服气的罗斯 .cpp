#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T,a,b,c,d;
    int ans1,ans2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        ans1 = 10 * a + 2 * b + 5 * c;
        scanf("%d%d%d",&a,&b,&c);
        ans2 = 10 * a + 2 * b + 5 * c;
        if(ans1 > ans2)
            printf("Nefarian will be the last winner.\n");
        else if(ans1 < ans2)
            printf("Rangnaros will be the last winner.\n");
        else printf("Once again.\n");
        scanf("%d",&d);
    }
    return 0;
}
