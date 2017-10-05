//看博客之后写的
#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;
const int maxn=102;
struct node
{
    char data; //存点的数据
    int x,y;
    int prex,prey;  //保存用最短时间到这个点的点的上一个坐标
    int step;       //走到当前所需步数
    friend bool operator<(node a,node b)    //重载，步数优先
    {
        return b.step<a.step;
    }
};
int n,m,x1,x2,y1,y2;
int inf=9999999;
int to[4][2]={-1,0,1,0,0,1,0,-1};
struct node s[maxn][maxn];      //记录地图和其中的一些信息
int bfs()
{
    priority_queue<node>q;
    while(!q.empty())
        q.pop();
    int i,x,y;
    struct node cur;
    s[x1][y1].step=0;
    q.push(s[x1][y1]);
    while(!q.empty())
    {
       // printf("111111\n");
        cur=q.top();
        q.pop();
        //到终点
        if(cur.x==x2&&cur.y==y2)
            return 1;
        for(i=0;i<4;i++)
        {
         //   printf("222222\n");
            x=cur.x+to[i][0];
            y=cur.y+to[i][1];
            if(x>=0&&x<n&&y>=0&&y<m&&s[x][y].data!='X')
            {
            //    printf("3333333\n");
                if(s[x][y].data=='.'&&s[x][y].step>cur.step+1) //+1是从cur走过来的花费
                {
              //      printf("444444\n");
                    s[x][y].step=cur.step+1;
                    s[x][y].prex=cur.x;
                    s[x][y].prey=cur.y;
                    q.push(s[x][y]);
                }
                else
                if(s[x][y].data>='1'&&s[x][y].data<='9'&&s[x][y].step>cur.step+s[x][y].data-'0'+1)
                {
               //     printf("555555\n");
                    s[x][y].step=cur.step+s[x][y].data-'0'+1;
                    s[x][y].prex=cur.x;
                    s[x][y].prey=cur.y;
                    q.push(s[x][y]);
                }
            }
        }

    }
    return 0;
}
void output(int x,int y)
{
    if(x==x1&&y==y1)
        return;
    int prex=s[x][y].prex;
    int prey=s[x][y].prey;
    output(prex,prey);//递归直至起始点
    int preTime=s[prex][prey].step;//得记录之前那个点的时间，因为要根据时间差来判断是否在该点打了怪兽
    int time=s[x][y].step;
    printf("%ds:(%d,%d)->(%d,%d)\n",preTime+1,prex,prey,x,y);
    for(int i=preTime+2;i<=time;i++)//没打怪兽的话，时间差应该是1，大于1说明打了怪兽
        printf("%ds:FIGHT AT (%d,%d)\n",i,x,y);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        getchar();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%c",&s[i][j].data);
                s[i][j].x=i;
                s[i][j].y=j;
                s[i][j].step=inf;
            }
            getchar();
        }
        x1=y1=0;
        x2=n-1;
        y2=m-1;
        int m=bfs();
        if(m==0)
        {
            printf("God please help our poor hero.\n");
            printf("FINISH\n");
        }
        else
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",s[x2][y2].step);
            output(x2,y2);
            printf("FINISH\n");
        }
    }
    return 0;
}





//最开始写的，没法记录

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//using namespace std;
//const int maxn=101;
//char s[maxn][maxn];
//int n,m,x1,x2,y1,y2;
//int to[4][2]={-1,0,1,0,0,1,0,-1},visit[maxn][maxn];
//struct Node
//{
//    int x,y;
//    int prex,prey;
//    int step;
//    friend bool operator<(Node n1,Node n2)
//    {
//        return n2.step<n1.step;
//    }
//};
//int Bfs()
//{
//  //  printf("1111111\n");
//    priority_queue<Node>q;
//    Node a,next;
//    a.x=x1;
//    a.y=y1;
//    a.prex=a.prey=0;
//    a.step=0;
//    q.push(a);
//    visit[x1][y1]=0;
//    while(!q.empty())
//    {
//    //    printf("2222222\n");
//        a=q.top();
//        q.pop();
//        if(a.x==x2&&a.y==y2)
//        {
//           printf("%ds:(%d,%d)->(%d,%d)\n",a.step,a.prex,a.prey,a.x,a.y);
//            return a.step;
//        }
//        for(int i=0;i<4;i++)
//        {
//    //        printf("333333\n");
//            next=a;
//            next.x+=to[i][0];
//            next.y+=to[i][1];
//            next.prex=a.x;
//            next.prey=a.y;
//            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&s[next.x][next.y]!='X'&&visit[next.x][next.y])
//            {
//                next.step++;
//                if(s[next.x][next.y]>='1'&&s[next.x][next.y]<='9')
//                {
//                    for(int j=0;j<s[next.x][next.y]-'0';j++)
//                    {
//                        next.step++;
//                       //printf("%ds:FIGHT AT (%d,%d)\n",next.step,next.x,next.y);
//                    }
//                }
//                if(visit[next.x][next.y]>next.step)
//                {
//                    visit[next.x][next.y]=next.step;
//                    q.push(next);
//                  //printf("%ds:(%d,%d)->(%d,%d)\n",next.step,next.prex,next.prey,next.x,next.y);
//                }
//            }
//        }
//    }
//    return 0;
//
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        getchar();
//        memset(s,0,sizeof(s));
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                scanf("%c",&s[i][j]);
//            }
//            getchar();
//        }
//        x1=y1=0;
//        x2=n-1;y2=m-1;
//        memset(visit,1,sizeof(visit));
//        int ans=Bfs();
//        if(ans)
//            printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
//
//        else
//            printf("God please help our poor hero.\n");
//        printf("FINISH\n");
//    }
//}
