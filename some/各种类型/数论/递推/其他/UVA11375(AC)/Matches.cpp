#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

#define N 720

using namespace std;
struct bign
{
    int len,s[N];
    bign()
    {
        memset(s,0,sizeof s);
        len=1;
    }
    bign(int num) {*this=num;}
    string str()const
    {
        string res="";
        for(int i=0;i<len;i++)
			res=(char)(s[i]+'0')+res;
        if(res=="") res="0";
        return res;
    }
    bign operator = (const char* num)
    {
        int i;
        len=strlen(num);
        for (i=0;i<len;i++)
        {
            s[i]=num[len-i-1]-'0';
        }
        return *this;
    }
    bign operator =(int num)
    {
        char s[N];
        sprintf(s,"%d",num);
        *this=s;
        return *this;
    }
    bign operator + (const bign& b )const
    {
        bign c;
        c.len=0;
        int i,g=0;
        for (i=0,g=0;g||i<max(len,b.len);i++)
        {
            int x=g;
            if (i<len) x+=s[i];
            if (i<b.len) x+=b.s[i];
            c.s[c.len++]=x%10;
            g=x/10;
        }
        return c;
    }
};

istream& operator >>(istream &in, bign& x)
{
  string s;
  in >> s;
  x = s.c_str();
  return in;
}
ostream& operator <<(ostream &out, const bign& x)
{
  out << x.str();
  return out;
}

bign f[2010];
bign ans[2010];

int c[]={6,2,5,5,4,5,6,3,7,6};//代表数字i所需要的火柴数量

int main()
{
	memset(f,0,sizeof(f));
    f[0]=1;
    for (int i=0;i<=2001;i++)
    {
        for (int j=0;j<=9;j++)
        {
            if (i+c[j]<=2000 && !(i==0 && j==0))
            {
                f[i+c[j]]=f[i+c[j]]+f[i];
            }
        }
    }
    ans[0]=0;
    for (int i=1;i<=2001;i++)
    {
        ans[i]=ans[i-1]+f[i];
    }
	int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n>=6)
         cout<<ans[n]+1<<endl;
        else
        cout<<ans[n]<<endl;
    }
    return 0;
}
