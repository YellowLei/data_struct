#include <iostream>
#include <cstdio>

using namespace std;

int a[31];
int pow2[31];

int main()
{
	int n;
	a[0] = a[1] = a[2] = 0;
	pow2[0] = 1;
	for (int i = 1; i <= 30; i++)
	{
		pow2[i] = 2 * pow2[i - 1];
	}
	for (int i = 3; i <= 30; i++)
	{
		a[i] = pow2[i - 3];
		for (int j = 2; j <= i - 2; j++)
		{
			a[i] += (pow2[j - 2] - a[j - 2]) * pow2[i - j - 2];
		}
	}
	while (scanf("%d", &n) != EOF, n)
	{
		printf("%d\n", a[n]);
	}
    return 0;
}
