////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-23 02:51:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1203
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:364KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
double dp[10005],pro[10005];
int fee[10005],n,m;
//double min(double x,double y)
//{
//    return x>y?y:x;
//}
int main()
{
   // freopen("in","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %lf",&fee[i],&pro[i]);
            pro[i]=1.0-pro[i];//不被选的概率
        }
        for(int i=0;i<=n;i++)
        {
            dp[i]=1;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=n;j>=fee[i];j--)
            {
                dp[j]=min(dp[j],dp[j-fee[i]]*pro[i]);
            }
        }
        printf("%.1lf%%\n",(1-dp[n])*100);
    }
    return 0;
}
