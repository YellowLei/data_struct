#include<stdio.h>
int main()
{
    char x,y,z;
    while(scanf("%c%c%c",&x,&y,&z)!=EOF)
    {
    getchar();
    int  t,b,c,d;
    b=x;
    c=y;
    d=z;
    if(b>c)
    {
        t=b;b=c;c=t;
    }
    if(c>d)
    {
    t=c;c=d;d=t;
    }
    if(b>c)
    {
        t=b;b=c;c=t;
    }
    x=b;y=c;z=d;
    printf("%c %c %c\n",x,y,z);
    }
    return 0;
}



