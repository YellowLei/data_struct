//��������
int pow1(int a,intb)
{
    int r=1;
    while(b--)
        r*=a;
    return r;
}
//�������ݣ�һ�㣩
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
//�������ݣ�λ������ͬpow2��
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
//�������ݣ�λ���㣬�����ӣ�

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

//�ݹ��㷨,����һ��
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

 //ѭ���㷨
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
