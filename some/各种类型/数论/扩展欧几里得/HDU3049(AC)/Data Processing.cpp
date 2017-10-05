//(M/N)%mod=(M*e)%mod=(M%mod*e%mod)%mod=((a1%mod+...+an%mod)%mod*e%mod)%mod
//M=a1+a2+...+an
//e是M的逆元
#include<iostream>
#include<cstdio>

using namespace std;

const int mod=1000003;
const int maxn=40010;

long long a,b,d,x,y;
int pow2[maxn];

//得到a1%mod+...+an%mod中的各个项
void getPow2()
{
    pow2[0]=1;
    for(int i=1;i<=maxn;i++)
    {
        pow2[i]=(pow2[i-1]*2)%mod;
    }
}

//扩展欧几里得
void gcd(long long a,long long b,long long& d,long long& x,long long& y)
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

//求逆元
long long mod_equation(long long a,long long n)
{
    gcd(a,n,d,x,y);
    long long m=x*(1/d)%n;
    return (m%n+n)%n;
}

int main()
{
    int T,N,n;
    long long sum;
    scanf("%d",&T);
    getPow2();
    for(int k=1;k<=T;k++)
    {
        sum=0;
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&n);
            sum=(sum+pow2[n])%mod;
        }
        int tmp=mod_equation(N,mod)%mod;
        int ans=(sum*tmp)%mod;
        printf("Case %d:%I64d\n",k,ans);
    }
    return 0;
}
