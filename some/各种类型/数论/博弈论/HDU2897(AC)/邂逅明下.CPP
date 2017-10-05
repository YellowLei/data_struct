#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int sg[10000], _hash[10000];
void getsg(int n, int p, int q)
{
    int i, j;
    memset(sg,0,sizeof(sg));
    for(i=p+1;i<=n;i++)
    {
        memset(_hash,0,sizeof(_hash));
        for(j=p;j<=q;j++)
        {
            _hash[sg[i-j]]=1;
        }
        for(j=0;j<=n;j++)
        {
            if(_hash[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        printf("%d ",sg[i]);
    }
}

int main()
{
    int n,p,q;
    while(~scanf("%d%d%d",&n,&p,&q))
    {
        //getsg(n,p,q); 打表，找规律
        int x=n%(p+q);
        if(x>=1&&x<=p)
            printf("LOST\n");
        else
            printf("WIN\n");
    }
    return 0;
}



