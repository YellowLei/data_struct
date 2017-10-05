#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[1010];
char color[1010][20];

int main()
{
	int i,j,n,cnt;
	int maxn;
	while(scanf("%d",&n),n)
	{
		cnt = 0;
        char t[20];
        memset(a,0,sizeof(a));
		while(n--)
		{
			scanf("%s",&t);
			for(i = 0;i < cnt;i++)
			{
				if(strcmp(t,color[i]) == 0)
				{
					a[i]++;
                    break;
				}
			}
			if(i == cnt)
            {
                memcpy(color[cnt++],t,sizeof(t));
                a[i]++;
            }
		}
		for(j = 0,maxn = 0;j < cnt;j++)
            if(a[j] > a[maxn])
                maxn = j;
		printf("%s\n",color[maxn]);
	}
	return 0;
}
