////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-23 02:15:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2955
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:348KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int t,m[105];
double dp[10005],pro[105];
int main()
{
   // freopen("in","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        int n,sum=0;
        double p;
        memset(dp,0,sizeof(dp));
        scanf("%lf%d",&p,&n);
        p=1-p;//安全率
        for(int i=1;i<=n;i++)
        {
            scanf("%d%lf",&m[i],&pro[i]);
            sum+=m[i];
            pro[i]=1-pro[i];//同样转化为安全率
        }
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=sum;j>=m[i];j--)
            {
                dp[j]=max(dp[j],dp[j-m[i]]*pro[i]);
                //这里用的是乘法，所以要注意dp[0]=1!!!
            }
        }
        for(int i=sum;i>=0;i--)
        {
            if(dp[i]-p>0.000000001)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
