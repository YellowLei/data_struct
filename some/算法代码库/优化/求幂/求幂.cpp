//常规求幂
int pow1(int a,intb)
{
    int r=1;
    while(b--)
        r*=a;
    return r;
}
//二分求幂（一般）
int pow2(inta,intb)
{
int r=1,base=a;
while(b!=0)
{
    if(b%2)
        r*=base;
    base*=base;
    b/=2;
}
return r;
}
//二分求幂（位操作，同pow2）
int pow4(int a,int b)
{
    int r=1,base=a;
    while(b!=0)
    {
        if(b&1)
            r*=base;
        base*=base;
        b>>=1;
    }
    return r;
}
//快速求幂（位运算，更复杂）

int pow3(int x,int n)
{
    if(n==0)
		return 1;
    else
    {
        while((n&1)==0)
        {
            n>>=1;
            x*=x;
        }
    }
    int result=x;
    n>>=1;
    while(n!=0)
    {
        x*=x;
    if((n&1)!=0)
        result*=x;
    n>>=1;
    }
    return result;
}

//递归算法,用这一种
int pow5(int a,int b)
 {
     int tem = 1;
     if(b==0)
		 return 1;
     else
		 if(b==1)
			 return a;
     tem = pow5(a,b>>1);
     tem = tem*tem;
     if(b&1)
		 tem = tem * a;
     return tem;
 }

 //循环算法
 int pow6(int a,int b)
 {
     int tem=1,ret=a;
     while(b>0)
     {
         if(b&1)
			 tem = tem * ret;
         ret = ret*ret;
         b>>=1;
     }
     return tem;
 }
