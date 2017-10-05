#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
const int maxn=102;
char a[maxn][maxn];
void Dfs(int x,int y)
{
    if((x<1||x>m)&&(y<1||y>n))
        return;
    if(a[x][y]!='@')
        return;
    a[x][y]='*';
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            Dfs(x+i,y+j);
        }
    }
}
int main()
{
    while(cin>>m>>n&&m)
    {
        int sum=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>a[i][j];
            }
        }
       // printf("m=%d n=%d\n",m,n);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
               // printf("a[%d][%d]=%c",i,j,a[i][j]);
                if(a[i][j]=='@')
                {
                    Dfs(i,j);
                    sum++;
                }
            }
           // printf("\n");
        }
        cout<<sum<<endl;
    }
    return 0;
}
