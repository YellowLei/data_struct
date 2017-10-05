#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

const int maxn = 1010;
int target[maxn],n;

int main()
{
    while(scanf("%d",&n) && n)
    {
        while(scanf("%d",&target[1]) && target[1])
        {
            stack <int> s;
            int a = 1,b = 1,ok = 1;
            for(int i = 2;i <= n;i++)
                scanf("%d",&target[i]);
            while(b <= n)
            {
                if(a == target[b]){b++;a++;}    //顺序相同的可以一个个过去
                else if(!s.empty() && s.top() == target[b]){s.pop();b++;}   //b那边的等于栈顶的可以过去
                else if(a <= n){s.push(a++);}   //不相同的先入栈
                else{ok = 0;break;} //a全部入栈且没有满足的结束
            }
            printf("%s\n",ok ? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}
