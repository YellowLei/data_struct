#include <iostream>
#include <cstdio>

using namespace std;

long long n;
long long  a[10000000];
int k = 0;

//深搜遍历
void dfs(long long ans,int num4,int num7)
{
    if(num4 == 0 && num7 == 0)
    {
        a[k++] = ans;
        return ;
    }
    else if(num4 == 0)
    {
        dfs(ans * 10 + 7,num4,num7 - 1);
    }
    else if(num7 == 0)
    {
        dfs(ans * 10 + 4,num4 - 1,num7);
    }
    else {
        dfs(ans * 10 + 4,num4 - 1,num7);
        dfs(ans * 10 + 7,num4,num7 - 1);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 2;i <= 18;i += 2)
    {
        dfs(0,i/2,i/2);
    }
    while(T--)
    {
        long long n;
        scanf("%I64d",&n);
        if(n > 777777777444444444)
        {
            printf("44444444447777777777\n");
            continue;
        }
        //二分查找
        int left = 0,right = k;
        while(right > left)
        {
            int mid = (left + right) / 2;
            if(a[mid] < n)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        printf("%I64d\n",a[right]);
    }
    return 0;
}
