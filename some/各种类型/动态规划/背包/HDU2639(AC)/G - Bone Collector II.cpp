//博客上的代码
//HUD 2639
#include <stdio.h>
#include <string.h>

#define MAXN 105
#define MAXV 1005
#define MAXK 35

int main()
{
    int T,N,V,K;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,tag;
        int value[MAXN],volume[MAXN],f[MAXV][MAXK];
        int a[MAXK],b[MAXK];
        scanf("%d%d%d",&N,&V,&K);
        for(i=1;i<=N;i++)
        {
            scanf("%d",&value[i]);
        }
        for(i=1;i<=N;i++)
        {
            scanf("%d",&volume[i]);
        }
        memset(f,0,sizeof(f));
        tag=1;
        for(i=1;i<=N;i++)
        {
            for(j=V;j>=volume[i];j--)
            {
                for(k=1;k<=K;k++)
                {
                    a[k]=f[j-volume[i]][k]+value[i];
                    b[k]=f[j][k];
                }
                int x,y,z;
                x=y=z=1;
                a[k]=b[k]=-1;
                while(z<=K&&(y<=K||x<=K))
                {
                    if(a[x]>b[y])
                    {
                        f[j][z]=a[x++];
                    }
                    else
                    {
                        f[j][z]=b[y++];
                    }
                    if(f[j][z]!=f[j][z-1]) //每个解只放一个进去
                    {
                        z++;
                    }
                }
            }
        }
         printf("%d\n",f[V][K]);
    }
    return (0);
}
