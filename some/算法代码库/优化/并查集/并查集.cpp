
//查找x的祖先
int findFather(int x)
{
    int r=x;
    while (pre[r]!=r)
        r=pre[r];
    return  r;
}
//压缩路径后的函数
int findfather(int x)
{
    if(x != pre[x])
      pre[x] = findfather(pre[x]); // 路径压缩修改的是pre数组
    return pre[x];
}
//???不懂
int findFather(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];
    int i=x,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
//让x所在的集合和y所在的集合合并
void join(int x,int y)
{
    int fx=findFather(x),fy=findFather(y);
    if(fx!=fy)
        pre[fx]=fy;
}

//判断x和y是否在一个集合里面
bool same(int x,int y)
{
    return findFather(x)==findFather(y);
}

