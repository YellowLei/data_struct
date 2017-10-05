#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int p[10005],s[1000005],nextt[10005]={0};
void GetNext(int* p)
{
	int pLen = m;
	nextt[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			nextt[j] = k;
		}
		else
		{
			k = nextt[k];
		}
	}
}
int KmpSearch(int* s, int* p)
{
	int i = 0;
	int j = 0;
	int sLen = n;
	int pLen = m;
    GetNext(p);
	while (i < sLen && j < pLen)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = nextt[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -2;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        for(i=0;i<m;i++)
            scanf("%d",&p[i]);
        printf("%d\n",KmpSearch(s,p)+1);
    }
}
