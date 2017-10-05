#include <iostream>
#include<cstdio>
using namespace std;

char phone1[100005][15];
int phone[100005][15];
int value[1005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int stye1=0,stye2=0,sum=0;
        int n;
        scanf("%d",&n);
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=0;i<=n;i++)
            value[i]=b;
            getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=11;j++)
            {
                scanf("%c",&phone1[i][j]);
                phone[i][j]=phone1[i][j]-'0';
            }
            getchar();

            if(phone[i][11]==phone[i][7]&&phone[i][11]==phone[i][8]&&phone[i][11]==phone[i][9]&&phone[i][11]==phone[i][10])
                value[i]=a;
            if((phone[i][7]-phone[i][8]==1)&&(phone[i][8]-phone[i][9]==1)&&(phone[i][9]-phone[i][10]==1)&&(phone[i][10]-phone[i][11]==1))
                value[i]=a;
            if((phone[i][7]-phone[i][8]==-1)&&(phone[i][8]-phone[i][9]==-1)&&(phone[i][9]-phone[i][10]==-1)&&(phone[i][10]-phone[i][11]==-1))
                value[i]=a;

            int years=1000*phone[i][4]+100*phone[i][5]+10*phone[i][6]+phone[i][7];
            int months=10*phone[i][8]+phone[i][9];
            int days=10*phone[i][10]+phone[i][11];
            if(years>=1980&&years<=2016&&months<=12&&months>=1&&days>=1&&days<=31)
            {
                if((years%100==0&&years%400==0)||years%100!=0&&years%4==0)//闰年
                {
                    if(months==2&&days>=1&&days<=29)
                        value[i]=a;
                    if((months==1||months==3||months==5||months==7||months==8||months==10||months==12)&&days>=1&&days<=31)
                        value[i]=a;
                    if((months==4||months==6||months==9||months==11)&&days>=1&&days<=30)
                        value[i]=a;
                }
                else
                {
                    if(months==2&&days>=1&&days<=28)
                        value[i]=a;
                    if((months==1||months==3||months==5||months==7||months==8||months==10||months==12)&&days>=1&&days<=31)
                        value[i]=a;
                    if((months==4||months==6||months==9||months==11)&&days>=1&&days<=30)
                        value[i]=a;
                }
            }
        }
        for(int i=1;i<=n;i++)
            sum+=value[i];
        printf("%d\n",sum);
    }
    return 0;
}
