#include<cstdio>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

const int maxn=30;
int n;
vector<int> pile[maxn];    //每个pile都是一个vector

//找到木块a所在的pile和height，以引用的形式返回调用者
void find_block(int a,int& p,int& h)
{
    for(p=0;p<n;p++)
    {
        for(h=0;h<pile[p].size();h++)
        {
            if(pile[p][h]==a)
                return;
        }
    }
}

//把第p堆高度为h的木块上方的所有木块移到原位
void clear_above(int p,int h)
{
    for(int i=h+1;i<pile[p].size();i++)
    {
        int b=pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);        //pile只应保留下标0-h的元素
}

//把第p堆高度为h及其上方的木块整体移动到p2堆的上方
void pile_onto(int p,int h,int p2)
{
    for(int i=h;i<pile[p].size();i++)
    {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

void print()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%d:",i);
        for(j=0;j<pile[i].size();j++)
        {
            printf(" %d",pile[i][j]);
        }
        if(i!=n-1)
            printf("\n");
    }
}

int main()
{
    int a,b;
    scanf("%d",&n);
    getchar();
    char s1[10],s2[10];
    for(int i=0;i<n;i++)
    pile[i].push_back(i);   //初始化每一堆一个数
    while(scanf("%s",s1)!=EOF)
    {
        if(s1[0]=='q')
            break;
        scanf("%d%s%d",&a,s2,&b);
        getchar();
        int pa,pb,ha,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa==pb) continue;//非法指令
        if(s2[1]=='o')
            clear_above(pb,hb);
        if(s1[0]=='m')
            clear_above(pa,ha);
        pile_onto(pa,ha,pb);
    }
    print();
    return 0;
}




