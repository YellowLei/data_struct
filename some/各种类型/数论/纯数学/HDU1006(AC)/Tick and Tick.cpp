#include <iostream>
#include <cstdio>

using namespace std;

//const double w_h=1.0/120,w_m=1./10,w_s=6.0; //角速度,时分秒
const double hm=11.0/120,hs=719.0/120,sm=59.0/10;//相对角速度,时分，时秒，分秒
const double T_hm=43200.0/11,T_hs=43200.0/719,T_sm=3600.0/59;//相对周期，相对周期就是时针和分针出现重复的相对关系的最小时间。

double Max(double a,double b,double c)
{
    double temp = (a > b) ? a : b;
    return (temp > c) ? temp : c;
}

double Min(double a,double b,double c)
{
    double temp = (a < b) ? a : b;
    return (temp < c) ? temp : c;
}

int main()
{
    double degree;
    double x[3],y[3];//记录的是第一个开始满足条件的时间和第一个开始不满足条件的时间
    double m[3],n[3];//根据相对周期来扩大x[3],y[3]以获得所有满足条件的时间集合，并求交集
    double Begin,End,sum;

    while(scanf("%lf",&degree),degree != -1)
    {
        x[0] = degree / hm;//第一次满足条件的时间
        x[1] = degree / hs;
        x[2] = degree / sm;

        y[0] = (360 - degree) / hm;//第一个开始不满足时间的条件
        y[1] = (360 - degree) / hs;
        y[2] = (360 - degree) / sm;

        sum = 0.0;

        //求(m[0],n[0),(m[1],n[1]),(m[2],n[2])的重复部分
        for(m[0] = x[0],n[0] = y[0];n[0] <= 43200.000001;m[0] += T_hm,n[0] += T_hm)
        {
            for(m[1] = x[1],n[1] = y[1];n[1] <= 43200.000001;m[1] += T_hs,n[1] += T_hs)
            {
                if(n[0] < m[1]) //说明(m[0],n[0),(m[1],n[1])不相交
                    break;
                if(m[0] > n[1]) //(m[1],n[1])比(m[0],n[0])小，继续增加可能相交
                    continue;
                for(m[2] = x[2],n[2] = y[2];n[2] <= 43200.000001;m[2] += T_sm,n[2] += T_sm)
                {
                    if(n[0]<m[2] || n[1]<m[2])
                        break;
                    if(m[0]>n[2] || m[1]>n[2])
                        continue;

                    Begin = Max(m[0],m[1],m[2]);
                    End = Min(n[0],n[1],n[2]);

                    if(End > Begin)
                        sum += End - Begin;
                }
            }
        }
        printf("%.3lf\n",sum * 100.0 / 43200);
    }
    return 0;
}
