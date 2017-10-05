#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=21;
int m,n;
int ans=0;
char a[maxn][maxn];
void Dfs(int x,int y)
{
    if((x<1||x>n)&&(y<1||y>m))
        return ;
    if(a[x][y]!='.'&&a[x][y]!='@')
        return ;
    a[x][y]='#';
    ans++;
    Dfs(x-1,y);
    Dfs(x+1,y);
    Dfs(x,y+1);
    Dfs(x,y-1);
}
int main()
{
    int x,y;
    while(scanf("%d%d",&m,&n),m)
    {
        for(int i=0;i<maxn;i++)
            for(int j=0;j<=maxn;j++)
            a[i][j]='#';
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%c",&a[i][j]);
//              printf("a[%d][%d]=%c\n",i,j,a[i][j]);
                if(a[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
            }
            getchar();
        }

        Dfs(x,y);
//        printf("x=%d y=%d\n",x,y);
//
//        printf("\n");
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=m;j++)
//            {
//                printf("%c",a[i][j]);
//            }
//            printf("\n");
//        }
        printf("%d\n",ans);
        ans=0;
    }
}
