/*
#include<iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    char a[4][28]={"|#.#.#.#.#.#.#.#.#.#.#.|D|)","|#.#.#.#.#.#.#.#.#.#.#.|.|","|........................|","|#.#.#.#.#.#.#.#.#.#.#.|.|)"};
    while(scanf("%d",&n)!=EOF)
    {
        cout<<"+------------------------+"<<endl;
        if(n<=4)
            for(int i=0;i<n;i++)
            {
                a[i][1]='O';
            }
        if(n>4)
        {
            int x,y;
            x=(n-4)/3;
            y=(n-4)%3;
            for(int i=0;i<4;i++)
            {
                a[i][1]='O';
            }
            for(int i=3;i<=2*x+1;i+=2)
            {
                a[0][i]='O';
                a[1][i]='O';
                a[3][i]='O';
            }
            if(y==1)
                a[0][2*x+3]='O';
            else if(y==2)
                a[0][2*x+3]='O';
                a[1][2*x+3]='O';
        }
        for(int i=0;i<4;i++)
        {
            if(i==0||i==3)
            {
                for(int j=0;j<28;j++)
                    cout<<a[i][j];
                cout<<endl;
            }
            if(i==1||i==2)
            {
                for(int j=0;j<27;j++)
                    cout<<a[i][j];
                cout<<endl;
            }

        }
        cout<<"+------------------------+"<<endl;
    }
    return 0;
}

*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        char a[6][30] ={
                            "+------------------------+",
                            "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
                            "|#.#.#.#.#.#.#.#.#.#.#.|.|",
                            "|#.......................|",
                            "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
                            "+------------------------+"
                         };

    for(int i = 1; n; i += 2)
        {
            for(int j = 1; j <= 4 && n; j++)
            {
                if(a[j][i] == '#')
                {
                    n--;
                    a[j][i] = 'O';
                }
            }
        }
    for(int i = 0; i < 6; i++)
        puts(a[i]);
    }

    return 0;
}
