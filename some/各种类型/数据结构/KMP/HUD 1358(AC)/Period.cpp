#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000010;
char s[maxn];
int nextt[maxn];
void GetNext(char* p)
{
    int plen=strlen(p);
    nextt[0]=-1;
    int k=-1;
    int j=0;
    while(j<plen)
    {
        if(k==-1||p[j]==p[k])
        {
            ++k;
            ++j;
            nextt[j]=k;
        }
        else
        {
            k=nextt[k];
        }
    }
}
int main()
{
    int n,len,times=0;
    while(scanf("%d",&n),n)
    {
        times++;
        scanf("%s",s);
        GetNext(s);
//        for(int i=0;i<n;i++)
//            printf("%d ",nextt[i]);
//        printf("\n");
        printf("Test case #%d\n",times);
        for(int i=1;i<=n;i++)
        {
            //next[i+1]前面有i+1个字符，i+1必须是最小循环序列的整数倍
            //前i+1-nextt[i+1]个字符是最小的循环，
            if(nextt[i+1]!=0&&(i+1)%(i+1-nextt[i+1])==0)
            {
                printf("%d %d\n",i+1,(i+1)/(i+1-nextt[i+1]));
            }
        }
        printf("\n");
    }
}
