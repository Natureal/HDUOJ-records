////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-16 21:14:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1158
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
#define INF 10000000
using namespace std;
int n,h,s,f,num[13],pmax,dp[13][1005];
int main()
{
	while(scanf("%d",&n) != EOF && n)
	{
		pmax = 0;
		scanf("%d %d %d",&h,&s,&f);
		for(int i = 1 ; i <= n ; i ++)
		{
			scanf("%d",&num[i]);
			if(num[i] > pmax)
				pmax = num[i];
		}
		for(int i = num[1] ; i <= pmax ; i ++)
		{
			dp[1][i] = i * (h + s);
		}
		for(int i = 2 ; i <= n ; i ++)
		{
			for(int j = num[i] ; j <= pmax ; j ++)
			{
				//dp[i][j]定下第i个月要留j个人
				int tmin = INF;
				for(int k = num[i - 1] ; k <= pmax; k ++)
				{
					//枚举上一月所留人的所有情况
					if(k > j)//上月留的人比这月计划的多，要fire
					{
						tmin = min(tmin,dp[i - 1][k] + (k - j) * f + j * s);
					}
					else
					{
						tmin = min(tmin,dp[i - 1][k] + (j - k) * h + j * s);
					}
				}
				dp[i][j] = tmin;
			}
		}
		int ans = INF;
		for(int i = num[n];i <= pmax;i ++)
		{
			ans = min(ans,dp[n][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}