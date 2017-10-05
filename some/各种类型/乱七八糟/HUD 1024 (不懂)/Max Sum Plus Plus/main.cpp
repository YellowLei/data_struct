//不懂
#include <cstdio>
#include <algorithm>
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
using namespace std;

int n, m, t;
long long d[1005], l[1005];

int main(){
	while(scanf("%d %d", &m, &n) != EOF)
    {
		FI(i, 1, m) d[i] = l[i] = -1e15;

		while(n--){
			scanf("%d", &t);
			FD(i, m, 1){
				d[i] = max(d[i], l[i - 1]) + t;
				l[i] = max(l[i], d[i]);
			}
		}
		printf("%d\n", l[m]);
	}
}

/*
//找的
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int Max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int curr[1000010],pre[1000010],arr[1000010];//curr保存当前状态
const int MAX = -1000000001;
int max_sum = 0;
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        memset(curr,0,sizeof(curr));
        memset(pre,0,sizeof(pre));
        int j=0;
        for(int i=1;i<=m;i++)
        {
            max_sum = MAX;
            for(j=i;j<=n;j++)
            {
                curr[j] = Max(curr[j-1],pre[j-1])+arr[j];
                pre[j-1] = max_sum;//这两条语句不能写反了，这块我纠结了好久，解释一下，prev_best[j-1]表示的是上一个状态中i...j-1的最大值，max_sum更新之后表示的i...j的最大值，所以不能写反了
                max_sum = Max(max_sum,curr[j]);
            }
                pre[j-1] = max_sum;//prev[j-1]中始终保持着前一个状态的最大值
        }
        printf("%d\n",max_sum);
    }
}
*/
/*
//我想的  ，不对
#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;
void BubbleSort(int *list,int len)
{
    int i,j,temp;
    for(i=0;i<len;i++)
        for(j=0;j<len-1;j++)
        {
            if(list[j]<list[j+1])
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
}
const int MAX=1000005;
int arr[MAX],order[MAX],b[MAX],dp[MAX];
int main()
{
    int n,m;
    int inf=-99999;
    while(scanf("%d %d",&m,&n))
    {
        int maxn=0,max1=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            order[i]=arr[i];
        }
        BubbleSort(order,n);
        for(int i=0;i<m;i++)
        {
           maxn+= order[i];
        }
        int start = 0,endd = 0,maxx = -1001;
        int first = 0,second = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i-1]>=0)
            {
                dp[i] = dp[i-1]+arr[i];endd = i;
            }
            else {
                dp[i] = arr[i];start = endd = i;
            }
            //输出最大的且只输出第一种情况
            if(maxx<dp[i])
            {
                maxx = dp[i];first = start;second = endd;
                if(maxx>order[m-1])
                {
                    memset(b,inf,sizeof(b));
                    max1=0;
                    for(int j=0;j<n;j++)
                    {
                        if(j<first||j>second)
                            b[j]=arr[j];
                    }
                    b[first]=maxx;
                    BubbleSort(b,n);
                    for(int j=0;j<m;j++)
                    {
                       max1+= b[j];
                    }
                    if(max1>maxn)
                    {
                        maxn=max1;
                    }
                }
            }
        }
        printf("%d\n",maxn);
    }
}
*/
