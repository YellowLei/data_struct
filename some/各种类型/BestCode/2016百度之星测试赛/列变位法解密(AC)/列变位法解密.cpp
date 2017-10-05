#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100005;

int main()
{
    int T;
    char s[maxn];
    char vis[maxn];
    int k,a,b,v,len;
    int change[maxn];
    scanf("%d",&T);
    getchar();
    for(int t = 1;t <= T;t++)
    {
        memset(vis,'\0',sizeof(vis));
        gets(s);
        scanf("%d",&k);
        getchar();
        len = strlen(s);
        if(k == 1)
        {
            printf("Case #%d:\n%s\n",t,s);
            continue;
        }
        a = len / k;
        b = len % k;
        int tmp = b;
        for(int i = 1;i < k;i++)
        {
             if(tmp != 0)
             {
                 change[i] = change[i - 1] + (a + 1);
                 tmp--;
             }
             else change[i] = change[i - 1] +  a ;
        }
        v = 0;
        for(int i = 0;i < a;i++)
        {
            for(int j = 0;j < k;j++)
            {
                vis[v++] = s[i + change[j]];
            }
        }
        for(int i = 0;i < b;i++)
        {
            vis[v++] = s[a + change[i]];
        }
        vis[v] = '\0';
        printf("Case #%d:\n%s\n",t,vis);
    }
    return 0;
}
/*
//其他方法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T,k;
char s[100005];
int a[1000005];

int main()
{
    int Case=1;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        getchar();
        gets(s);
        scanf("%d",&k);
        int l=strlen(s),p=1,j,i=1;
        printf("Case #%d:\n",Case++);
        while (i<=k)
        {
            j=0;
            while (i+j<=l)
            {
                a[i+j]=p++;
                j+=k;
            }
            i++;
        }
        //sort(a+1,a+l+1);
        for (int i=1;i<=l;i++)
			printf("%c",s[a[i]-1]);
        printf("\n");
    }
    return 0;
}
*/

