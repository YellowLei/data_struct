#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char name1[30];
        char name2[30];
        char op1[30];
        char op2[30];
        scanf("%s : %s",name1,op1);
        scanf("%s : %s",name2,op2);
        if(op1[0] == op2[0])
            printf("Once again.\n");
        else
        {
            if(op1[0] == 'r')
            {
                if(op2[0] == 's')
                    printf("%s ",name1);
                else printf("%s ",name2);
            }
            else if(op1[0] == 's')
            {
                if(op2[0] == 'r')
                    printf("%s ",name2);
                else printf("%s ",name1);
            }
            else if(op1[0] == 'c')
            {
                if(op2[0] == 'r')
                    printf("%s ",name1);
                else printf("%s ",name2);
            }
            printf("will be the winner.\n");
        }
    }

    return 0;
}
