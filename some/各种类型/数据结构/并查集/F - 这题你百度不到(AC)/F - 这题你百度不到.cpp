#include<iostream>
#include<cstdio>

using namespace std;

const int MAX=1005;
int pre[MAX*MAX],value[MAX*MAX],to[4][2]={-1,0,1,0,0,1,0,-1};

int findFather(int x)
{
    if(pre[x]!=x)
        pre[x]=findFather(pre[x]);
    return pre[x];
}

void join(int x,int y)
{
    int fx=findFather(x);
    int fy=findFather(y);
    if(fx!=fy)
    {
        if(value[fx]<value[fy])
            value[fx]=value[fy];
        pre[fy]=fx;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M,x,y,c;
        char oper[5];
        scanf("%d %d",&N,&M);
        for(int i=1;i<=N*N;i++)
        {
            pre[i]=i;
            value[i]=-1;
        }
        for(int i=1;i<=M;i++)
        {
            scanf("%s",oper);
            if(oper[0]=='C')
            {
                scanf("%d%d%d",&x,&y,&c);
                value[(x-1)*N+y]=c;
                for(int j=0;j<4;j++)
                {
                    int x1=x+to[j][0];
                    int y1=y+to[j][1];
                    if(value[(x1-1)*N+y1]!=-1&&0<x1&&x1<=N&&0<y1&&y1<=N)
                        {
         //                   printf("x1=%d y1=%d j==%d value[%d]=%d\n",j,x1,y1,(x1-1)*N+y1,value[(x1-1)*N+y1]);
                            join((x-1)*N+y,(x1-1)*N+y1);
                        }
                }
            }
            else
            {
                scanf("%d%d",&x,&y);
                int sum=findFather((x-1)*N+y);
                printf("%d\n",value[sum]);
            }
        }
    }
    return 0;
}
