#include<cstdio>
int maxn(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int a,b,c;
    int ans;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        ans=0;
        ans=maxn(ans,a+b*c);
        ans=maxn(ans,a*(b+c));
        ans=maxn(ans,a*b*c);
        ans=maxn(ans,(a+b)*c);
        ans=maxn(ans,a+b+c);
        ans=maxn(ans,a*b+c);
        printf("%d\n",ans);
    }
    return 0;
}
/*

#include<stdio.h>
int max(int,int);
int main()
{
    int a[3],t,x,y;
    while(scanf("%d%d%d",&a[0],&a[1],&a[2])!=EOF)
    {
        if(a[0]<a[1])
            {
                t=a[0];
                a[0]=a[1];
                a[1]=t;
            }
        if(a[0]<a[2])
            {
                t=a[0];
                a[0]=a[2];
                a[2]=t;
            }
        x=max(a[1],a[2]);
        printf("%d\n",max(x,a[0]));
    }
    return 0;
}
int max(int x,int y)
{
    if((x+y)>(x*y))
        return x+y;
    else
        return x*y;
}

*/
