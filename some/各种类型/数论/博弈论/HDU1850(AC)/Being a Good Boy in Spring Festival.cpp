#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int main()
{
    int m,n[110];
    while(scanf("%d",&m)&&m)
    {
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&n[i]);
            ans^=n[i];  //改题可以取任意数，所以sg[i]=i
        }
        if(ans==0)
            printf("0\n");
        else
        {
            int last=0;
            for(int i=1;i<=m;i++)
            {
                //(ans^n[i]为不包含n[i]的子问题，(ans^n[i])<n[i]就可以在n[i]中取数使(ans^n[i])^n[i]'==0
                if((ans^n[i])<n[i])
                    last++;
            }
            printf("%d\n",last);
        }
    }
    return 0;
}
