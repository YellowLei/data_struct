//欧拉函数phi(n)=n(1-1/p1)(1-1/p2)...(1-1/pk)
//用于求小于n且与n互素的整数个数

int euler_phi(int n)
{
    int m = (int)sqrt(n + 0.5);
    int ans = n;
    for(int i = 2;i <= m;i++)
    {
        if(n % i == 0)
        {
            ans = ans / i * (i-1);//phi(n)=n(1-1/p1)(1-1/p2)...(1-1/pk)
            //找到一个素因子将其除干净，即可保证找到的因子都是素因子
            while(n % i == 0)
                n /= i;
        }
    }
    //n本身就是素数或   n是素数p的k次幂，除了素数p的倍数外，其他数都跟素数n互质phi(n)=(p-1)*p^(k-1)
    if(n > 1)
        ans = ans / n * (n-1);
    return ans;
}

//1~n中所有数的欧拉phi函数值
void phi_table(int n,int* phi)
{
    for(int i = 2;i <= n;i++)
    {
        phi[i] = 0;
    }
    phi[1] = 1; //小于1且与1互素的整数个数
    for(int i = 2;i <= n;i++)
    {
        if(!phi[i])
        {
            for(int j = i;j <= n;j += i)
            {
                if(!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i-1); //phi[j]=phi[j](1-1/pk)=[n(1-1/p1)(1-1/p2)...](1-1/pk)
            }
        }
    }
}









