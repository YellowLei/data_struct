#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int  a[10010],b[10010];

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i = 0;i < n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);

//慢一些
//        for(int i = 1;i < n;i++)
//        {
//            b[i] = a[i] - a[i-1];
//        }
//        sort(b,b+n);
//        double ans = (b[n-1]*1.0)/2;

        int  max1=0;
        for (int i=1;i<n;i++)
			max1=max(max1,a[i]-a[i-1]);
        double ans=max1*1.0/2;

        if(ans < a[0]*1.0)
            ans = a[0]*1.0;
        if(ans < (m - a[n-1])*1.0)
            ans = (m - a[n-1])*1.0;
        printf("%.2lf\n",ans);
    }
    return 0;
}
