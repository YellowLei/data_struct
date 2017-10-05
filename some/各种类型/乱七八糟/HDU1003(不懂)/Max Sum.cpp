#include<iostream>
using namespace std;
int arr[100001],dp[100001];
int main() {
    int T,n,i=1;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        dp[0] = arr[0];
        int start = 0,endd = 0,maxx = -1001;
        int first = 0,second = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i-1]>=0)
            {
                dp[i] = dp[i-1]+arr[i];endd = i;
            }
            else {
                dp[i] = arr[i];start = endd = i;
            }
            //输出最大的且只输出第一种情况
            if(maxx<dp[i]) {
                maxx = dp[i];first = start;second = endd;
            }
        }
        cout<<"Case "<<i++<<":"<<endl<<maxx<<" "<<first+1<<" "<<second+1<<endl;
        if(T!=0)
            cout<<endl;
    }
}




//#include<stdio.h>
//main()
//{
//	int a[100010];
//	int case_number,i,begin,position,end,n,thisnumber,maxnumber,k=0;
//	scanf("%d",&case_number); //输入测试用例
//		while(case_number--)
//		{
//			k++;
//			scanf("%d",&n);
//			for(i=0;i<n;i++)
//				scanf("%d",&a[i]);
//			begin=position=end=0;
//			thisnumber=maxnumber=a[0];
//			for(i=1;i<n;i++)
//			{
//				if(thisnumber+a[i]<a[i])
//				{
//					thisnumber=a[i];
//					position=i;
//				}
//				else
//				{
//					thisnumber=thisnumber+a[i];
//				}
//				if(thisnumber>maxnumber)
//				{
//					maxnumber=thisnumber;
//					begin=position;
//					end=i;
//				}
//
//			}
//			printf("Case %d:\n%d %d %d\n",k,maxnumber,begin+1,end+1);
//			if(case_number)
//				printf("\n");
//		}
//		return 0;
//}
