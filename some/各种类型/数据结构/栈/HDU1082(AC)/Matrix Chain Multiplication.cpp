//关键：解析表达式，有')'才计算
#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

struct Matrix
{
    int a,b;
    Matrix(int a = 0,int b = 0):a(a),b(b){}
}m[26];

stack <Matrix> s;

int main()
{
    int n;
    char name[5];
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%s",name);
        int k = name[0] - 'A';
        scanf("%d%d",&m[k].a,&m[k].b);
    }
    string exp;
    while(cin >> exp)
    {
        int len = exp.length();
        bool error = false;
        int ans = 0;
        for(int i = 0;i < len;i++)
        {
            if(isalpha(exp[i]))
                s.push(m[exp[i] - 'A']);    //是字母入栈
            else if(exp[i] == ')')          //碰到')'计算
            {
                Matrix m2 = s.top();s.pop();    //取出第一个矩阵
                Matrix m1 = s.top();s.pop();    //取出第二个矩阵
                if(m1.b != m2.a)    //不满足条件
                {
                    error = true;
                    break;
                }
                ans += m1.a * m2.a * m2.b;
                s.push(Matrix(m1.a,m2.b));
            }
        }
        if(error)
            printf("error\n");
        else printf("%d\n",ans);
    }
    return 0;
}
