#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,m,a[100][100],b[100][100],i,j,x=1,y=1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int max=0;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]<0)
				b[i][j]=abs(a[i][j]);
				else
				b[i][j]=a[i][j];
				if(b[i][j]>max)
				{
                    max=b[i][j];
                    x=i;
                    y=j;
			    }
			}
		}

		printf("%d %d %d\n",x,y,a[x][y]);

}
return 0;
}
