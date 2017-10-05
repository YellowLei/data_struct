int a,b,d,x,y;
void gcd(int a,int b,int &d,int &x,int &y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}

//使用扩展欧几里德算法解决不定方程的办法：不定整数方程pa+qb=c
bool linear_equation(int a,int b,int c,int &x,int &y)
{
    gcd(a,b,d,x,y);
    //只有当c是gcd(a,b)的整数倍是才有解
    if(c%d)
        return false;
    int k=c/d;
    x*=k; y*=k;    //求得的只是其中一组解
    return true;
}

//用扩展欧几里德算法求解模线性方程的方法：ax≡b (mod n)
//ax≡b (mod n)等价于ax+ny=b(ax=n*k1+k,b=n*k2+k,相减得ax+(k2-k1)n=b)

//如果可以设法找到第一个解，并且求出解之间的间隔，那么就可以求出模的线性方程的解集了.
//我们设解之间的间隔为dx.
//那么有
//a*x = b(mod n);
//a*(x+dx) = b(mod n);
//两式相减，得到:
//a*dx(mod n)= 0;
//也就是说a*dx就是a的倍数，同时也是n的倍数，即a*dx是a 和 n的公倍数.为了求出dx,我们应该求出a 和 n的最小公倍数,此时对应的dx是最小的.
//设a 和 n的最大公约数为d,那么a 和 n 的最小公倍数为(a*n)/d.
//即a*dx = a*n/d;
//所以dx = n/d.

bool modular_linear_equation(int a,int b,int n)
{
    gcd(a,n,d,x,y);
    if(b%d)
        return false;
    int x0=x*(b/d)%n;   //特解，间隔为n/d
    for(int i=1;i<d;i++)
        printf("%d\n",(x0+i*(n/d))%n);
    return true;
}

//用欧几里德算法求模的逆元：ax≡1 (mod n)且gcd(a,n)= 1
//同余方程ax≡b (mod n)，如果 gcd(a,n)== 1，则方程只有唯一解。
//在这种情况下，如果 b== 1，同余方程就是 ax=1 (mod n ),gcd(a,n)= 1。
//这时称求出的 x 为 a 的对模 n 乘法的逆元
