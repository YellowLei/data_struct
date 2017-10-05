#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,t;
    while(scanf("%d",&n)!=EOF)
    {
        int  m=0,j=0;
        for(int i=0;i<n;i++)
            {
                cin>>t;
                if(t==1)
                {
                    if(j>=1&&m!=0)m++;
                    m++;
                    j=0;
                }
                if(t==0)j++;
            }
            cout<<m<<endl;
    }
    return 0;
}
