#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=205;
char s[maxn][maxn];
int n,m,rx,ry,ax,ay;
int to[4][2]={-1,0,1,0,0,1,0,-1},visit[maxn][maxn];
struct Node
{
    int x;
    int y;
    int step;
    //重载“<”操作符的方法来修改优先队列的优先性,以step为优先级
    friend bool operator<(Node n1,Node n2)
    {
        return n2.step<n1.step;
    }
};
int Bfs()
{
    priority_queue<Node>q;
    Node a,next;
    a.x=rx;
    a.y=ry;
    a.step=0;
    q.push(a);
    visit[rx][ry]=0;
    while(!q.empty())
    {
   //     printf("11111\n");
        a=q.top();
        q.pop();
        if(a.x==ax&&a.y==ay)
        {
    //        printf("a.step=%d\n",a.step);
            return a.step;
        }
        for(int i=0;i<4;i++)
        {
     //       printf("222222\n");
            next=a;
            next.x+=to[i][0];
            next.y+=to[i][1];
            if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m&&s[next.x][next.y]!='#'&&visit[next.x][next.y])
            {
      //          printf("33333\n");
                next.step++;
                if(s[next.x][next.y]=='x')
                    next.step++;
                //只选小的入队
                if(visit[next.x][next.y]>=next.step)
                {
                    visit[next.x][next.y]=next.step;
                    q.push(next);
                }
            }
        }
    }
    return 0;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%c",&s[i][j]);
                if(s[i][j]=='r')
                {
                    rx=i;
                    ry=j;
                }
                if(s[i][j]=='a')
                {
                    ax=i;
                    ay=j;
                }
            }
            getchar();
        }
        memset(visit,1,sizeof(visit));
        int ans=0;
        ans=Bfs();
        if(ans)
            printf("%d\n",ans);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
}
