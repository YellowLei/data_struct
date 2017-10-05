#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=1000;
typedef struct
{
    int from;
    int to;
    int d;
    int next;
}EdgeNode;
int main()
{
    int m,n;//顶点个数和边的条数
    int from,to,d,next;
    Edge e[MAX];        //e[i]指第几条边
    int pre[MAX];

    msmset(pre,-1,sizeof(pre));

    scanf("%d%d",&m,&n);

    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&from,&to,&d,&next);
        e[i].from=from;
        e[i].to=to;
        e[i].d=d;
        e[i].next=pre[from];
        pre[from]=i;
    }

}
