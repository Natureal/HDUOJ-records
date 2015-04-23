////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-08 21:23:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2159
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int dp[105][105],ren[105],jing[105];
	int n,m,k,s;
	while(scanf("%d %d %d %d",&n,&m,&k,&s)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= k;i ++)
		{
			scanf("%d %d",&jing[i],&ren[i]);
		}
		for(int i = 1;i <= k;i ++)//Ã¶¾ÙÃ¿Ö»¹Ö
		{
			for(int j = ren[i];j <= m; j ++)
			{
				for(int k = 1;k <= s;k ++)
				{
					dp[j][k] = max( dp[j][k] , dp[j - ren[i]][k - 1] + jing[i] );
				}
			}
		}
		int flag = -1;
		for(int j = 1;j <= m && flag == -1;j ++)
		{
			for(int k = 1;k <= s;k ++)
			{
				if(dp[j][k] >= n)
				{
					flag = j;
					break;
				}
			}
		}
		if(flag != -1)
		{
			printf("%d\n",m - flag);
		}
		else
			printf("-1\n");
	}
	return 0;
}