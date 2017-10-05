//假设单独买A或者B的话，都是可以买到的。这时，若先买A，则你至少需要p1+q2的钱；
//若先买B，则至少需要p2+q1的钱。那肯定是花最少的钱咯，所以如果先买A再买B，那么p1+q2<p2+q1，
//转换一下，就是q1-p1>q2-p2，也就是说qi-pi大的先买。这里还得注意一点就是，排序的时候，
//得按照qi-valuei从小到大排序，因为你买第n件商品的时候，是在比较你是否要先买第n件商品。

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=550;
struct Node
{
    int p,q,v;
}node[MAXN];
int dp[5500];
bool cmp(Node a,Node b)//按照 q-p 从小到大排序
{
    return a.q-a.p < b.q-b.p;   //<号就是升序，改为>就是降序
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
          scanf("%d%d%d",&node[i].p,&node[i].q,&node[i].v);
        sort(node,node+n,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
          for(int j=m;j>=node[i].q;j--)
            dp[j]=max(dp[j],dp[j-node[i].p]+node[i].v);
        printf("%d\n",dp[m]);
    }
    return 0;
}
