////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-10 23:00:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1081
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int max(int a,int b)
{
	return a>b ? a:b;
}
int main()
{
	int map[105][105],dp[105];
	int i,j,n,k;

	while(scanf("%d",&n)!=EOF)
	{
		for(i = 1;i <= n;i ++)
		{
			for(j = 1;j <= n ;j ++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		int maxn = 0;
		for(i = 1;i <= n ;i ++)
		{
			memset(dp,0,sizeof(dp));
			for(k = 1;k <= n;k ++)
			{
				dp[k] = max(dp[k-1]+map[i][k],map[i][k]);
				maxn = max(maxn,dp[k]);
			}
			for(j = i+1;j <= n;j ++)
			{
				memset(dp,0,sizeof(dp));
				for(k = 1;k <= n;k ++)
				{
					map[i][k] += map[j][k];
					dp[k] = max(dp[k-1]+map[i][k],map[i][k]);
					maxn = max(maxn,dp[k]);
				}
			}
		}
		printf("%d\n",maxn);
	}
	return 0;
}