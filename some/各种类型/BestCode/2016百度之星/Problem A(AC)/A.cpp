#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 9973;

struct Node
{
    int left;
    int right;
    int value;
};
Node node[1000005];
char s[200005];

void build(int root,int left,int right)
{
    node[root].left = left;
    node[root].right = right;
    if(left == right)
    {
        node[root].value = s[left-1] - 28;
        return ;
    }
    int mid = (left + right) / 2;
    build(root * 2,left,mid);
    build(root *2 +1,mid + 1,right);
    node[root].value = (node[root * 2].value * node[root * 2 + 1].value) % mod;
}

int Count(int root,int left,int right)
{
    if(node[root].left == left && node[root].right == right)
        return node[root].value;
    int mid = (node[root].left + node[root].right) / 2;
    if(right <= mid)
        return Count(root * 2,left,right);
    else if(mid < left)
        return Count(root * 2 + 1,left,right);
    else
    {
        int x = Count(root * 2,left,mid);
        int y = Count(root * 2 + 1,mid + 1,right);
        return (x * y) % mod;
    }

}
int main()
{
    int n,ans,a,b;
    while(~scanf("%d",&n))
    {
        memset(node,0,sizeof(node));
        memset(s,0,sizeof(s));
        scanf("%s",s);
        int len = strlen(s);
        build(1,1,len);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a < 1 || a > len || b < 1 || b > len)
                printf("%d\n",ans);
            else
            {
                ans = Count(1,a,b);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
/*
//超时
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n,a,b,ans;
    char s[100010];
    int cou[100010];
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        int l = strlen(s);
        for(int i = 1;i <= l;i++)
        {
            cou[i] = s[i-1] - 28;
        }
        for(int t = 1;t <= n;t++)
        {
            scanf("%d%d",&a,&b);
            if(a < 1 || a > l || b < 1 || b > l)
                printf("%d\n",ans);
            else
            {
                ans = 1;
                for(int i = a;i <= b;i++)
                {
                    ans = (ans * cou[i]) % 9973;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
*/
