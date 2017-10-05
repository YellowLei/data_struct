#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define ll long long

deque <ll> deq1,deq2;

ll a[100010];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        ll ans = 0,k;
        scanf("%d%I64d",&n,&k);
        for(int i = 0;i < n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        if(k == 0)
        {
            printf("0\n");
            continue;
        }
        while(!deq1.empty())
            deq1.pop_back();
        while(!deq2.empty())
            deq2.pop_back();
        int i,j;
        for(i = 0,j = 0;i < n;i++)
        {
            //最大值队列里比a[i]小的全部出队
            while( !deq1.empty() && deq1.back() < a[i] )
				deq1.pop_back() ;
            deq1.push_back(a[i]) ;
			//最小值队列比a[i]大的全部出队
            while( !deq2.empty() && deq2.back() > a[i] )
				deq2.pop_back() ;
            deq2.push_back(a[i]) ;
            //deq2.front()是j到i中最小的元素，deq1.front()是j到i中最大的元素
            //当deq1.front() - deq2.front() >= k就意味着新加入的a[i]不能作用于j的位置
            while( !deq1.empty() && !deq2.empty() && deq1.front() - deq2.front() >= k )
            {
                ans += (i-j) ;
                if( deq1.front() == a[j] )
					deq1.pop_front() ;
                if( deq2.front() == a[j] )
					deq2.pop_front() ;
                j++ ;
            }
        }
        while(j < n)
        {
            ans += (i - j);
            j++;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
/*
//超时
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100010;

int a[maxn];
int que[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if(k == 0)
        {
            printf("0\n") ;
            continue ;
        }
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        memset(que,0,sizeof(que));
        int head = 0;
        int endd = 0;
        for(int i = 1;i <= n;i++)
        {
            endd++;
            for(int j = head + 1;j < endd;j++)
            {
                if(a[i] - a[j] >= k || a[j] - a[i] >= k)
                {
                     head = j;
                }
            }
            for(int j = head + 1;j <= endd;j++)
            {
                que[j]++;
            }
        }
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            sum += que[i];
            //printf("que[%d]==%d\n",i,que[i]);
        }
        printf("%d\n",sum);
    }

    return 0;
}
*/
