#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100005;
int last,cur,Next[maxn];    //光标位于cur号字符的后面。关键
char s[maxn];

int main()
{
    while(scanf("%s",s+1) != EOF)
    {
        int n = strlen(s+1);    //输入保存在s[1],s[2]...
        last = cur = 0;
        Next[0] = 0;

        for(int i = 1;i <= n;i++)
        {
            char ch = s[i];
            if(ch == '[') cur = 0;
            else if(ch == ']') cur = last;
            else {
                Next[i] = Next[cur];
                Next[cur] = i;
                if(cur == last)last = i;    //跟新“最后一个字符”编号
                cur = i;        //移动光标
            }
        }
        for(int i = Next[0];i != 0;i = Next[i])
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
