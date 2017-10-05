//题目http://acm.hust.edu.cn/vjudge/contest/view.action?cid=85963#problem/C
//讲解http://blog.csdn.net/lgdblue/article/details/15809893


//f[]：可以取走的石子个数
//sg[]:0~n的SG函数值
//_hash[]:mex{}
int f[N],sg[N],_hash[N];
void getSG(int n)
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=n;i++)
    {
        memset(_hash,0,sizeof(_hash));
		//i-f[j]为子问题，sg[i-f[j]]为子问题的sg，子问题出现的赋值1
        for(j=1;f[j]<=i;j++)
            _hash[sg[i-f[j]]]=1;
        for(j=0;j<=n;j++)    //_hash[j]==0是未出现的最小的非负整数
        {
            if(_hash[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
    //可用于打表
    for(i=0;i<=n;i++)
    {
        printf("%d ",sg[i]);
    }
}

//打表
//注意 S数组要按从小到大排序 SG函数要初始化为-1 对于每个集合只需初始化1遍
//n是集合s的大小 S[i]是定义的特殊取法规则的数组
int s[110],sg[10010],n;
int SG_dfs(int x)
{
    int i;
    if(sg[x]!=-1)
        return sg[x];
    bool _hash[110];
    memset(_hash,0,sizeof(_hash));
    for(i=0;i<n;i++)
    {
        if(x>=s[i])
        {
            SG_dfs(x-s[i]);
            _hash[sg[x-s[i]]]=1;
        }
    }
    for(i=0;;i++)
        if(_hash[i]==0)
        {
            sg[x]=i;
            break;
        }
    return sg[x];
}
