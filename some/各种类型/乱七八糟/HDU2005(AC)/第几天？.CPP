#include<stdio.h>
int main()
{
    int x,y,z;
    while(scanf("%d/%d/%d",&x,&y,&z)!=EOF)
    {
        if((x%4==0&&x%100!=0)||(x%100==0&&x%400==0)||(x%3200==0&&x%172800==0))
        {
            if(y==1)
                printf("%d\n",z);
            else if(y==2)
                printf("%d\n",31+z);
            else if(y<=8)
                printf("%d\n",(y-1)*30+y/2+z-1);
            else
                printf("%d\n",(y-1)*30+(y+1)/2+z-1);
        }
        else
        {
            if(y==1)
                printf("%d\n",z);
            else if(y==2)
                printf("%d\n",31+z);
            else if(y<=8)
                printf("%d\n",(y-1)*30+y/2+z-2);
            else
                printf("%d\n",(y-1)*30+(y+1)/2+z-2);
        }
    }
    return 0;
}
