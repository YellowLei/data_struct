#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

char s[50];
int main()
{
    multiset<string> mul;
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%s",s);getchar();
        sort(s,s+strlen(s));
        mul.insert(s);
        printf("%d\n",mul.count(s) - 1);
    }
    return 0;
}
