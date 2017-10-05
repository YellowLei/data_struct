#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

struct point
{
    int x,y;
};
point a[105],Stack[105];
double distance(point a,point b)
{
    return (double)sqrt((a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y)*1.0);
}
double cross(point a,point n1,point n2)
{
    return (n1.x-a.x)*(n2.y-a.y)-(n1.y-a.y)*(n2.x-a.x);
}
bool cmp(point a,point b)
{
    if(a.y<b.y)
        return true;
    if(a.y==b.y&&a.x<b.x)
        return true;
    return false;
}
void Sort(int n)
{
    point temp;
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].y<a[k].y||(a[i].y==a[k].y&&a[i].x<a[k].x))
            k=i;
    }
    temp=a[0];
    a[0]=a[k];
    a[k]=temp;
    sort(a+1,a+n,cmp);
}
void Graham(int n)
{
    Sort(n);
    int head,sum;
    a[n]=a[0];
    Stack[0]=a[0];
    Stack[1]=a[1];
    Stack[2]=a[2];
    head=2;
    for(int i=3;i<=n;i++)
    {
        while(head>=2&&(cross(Stack[head-1],Stack[head],a[i])<=0))
            head--;
        Stack[++head]=a[i];
    }
    for(int i=0;i<head;i++)
    {
        sum+=distance(Stack[i],Stack[i+1]);
    }
    printf("%.2lf\n",sum);

}
int main ()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        if(n==1)
        {
            printf("0.00\n");
            continue;
        }
        if(n==2)
        {
            printf("%.2lf\n",distance(a[0],a[1]));
            continue;
        }
        Graham(n);
    }
    return 0;
}
