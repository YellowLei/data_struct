#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct node
{
    char data;
    int x,y;
    int step;
    friend bool operator<(node a,node b)
    {
        return b.step<a.step;
    }
};
int m,n,x1,y1,x2,y2;
int inf=9999999,dis[4][2]={-1,0,1,0,0,-1,0,1};
struct node s[25][25];
int bfs()
{
    priority_queue<node>q;
    while(!q.empty())
        q.pop();
    struct node cur;
    int i,x,y;
    s[x1][y1].step=0;
    q.push(s[x1][y1]);
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        if(cur.x==x2&&cur.y==y2)
            return 1;
        for(i=0;i<4;i++)
        {
           // printf("11111\n");
            x=cur.x+dis[i][0];
            y=cur.y+dis[i][1];
            if(x>=0&&x<m&&y>=0&&y<n)
            {
              //  printf("222222\n");
                if(s[x][y].data=='.'&&s[x][y].step>cur.step+1)
                {
              //      printf("3333333\n");
                    s[x][y].step=cur.step+1;
                    q.push(s[x][y]);
                }
                else if(((s[x][y].data=='-'&&(i==0||i==1))||(s[x][y].data=='|'&&(i==2||i==3)))&&s[x][y].step>cur.step+1)
                {
             //       printf("44444444\n");
                    s[x][y].step=cur.step+1;
                    q.push(s[x][y]);
                }
                else if(((s[x][y].data=='-'&&(i==2||i==3))||(s[x][y].data=='|'&&(i==0||i==1)))&&s[x][y].step>cur.step+2)
                {
              //      printf("5555555\n");
                    s[x][y].step=cur.step+2;
                    q.push(s[x][y]);
                }
            }
        }
    }
    return 0;
}
int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        getchar();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%c",&s[i][j].data);
                s[i][j].x=i;
                s[i][j].y=j;
                s[i][j].step=inf;
                if(s[i][j].data=='S')
                {
                    x1=i;
                    y1=j;
                }
                if(s[i][j].data=='T')
                {
                    x2=i;
                    y2=j;
                }
            }
            getchar();
        }
        int m=bfs();
        if(m==1)
        printf("%d\n",s[x2][y2].step);
    }
    return 0;
}
