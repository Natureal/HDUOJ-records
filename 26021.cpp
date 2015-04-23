////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-10 22:51:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:4164KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int dp[1001][1001],va[1001],vo[1001];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j,n,N,V;
	scanf("%d",&n);
	while(n--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&N,&V);
		for(i=1;i<=N;i++)
		{
			scanf("%d",&va[i]);
		}
		for(i=1;i<=N;i++)
		{
			scanf("%d",&vo[i]);
		}
		for(i=1;i<=N;i++)
		{
			for(j=0;j<=V;j++)
			{
				if(j>=vo[i])
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-vo[i]]+va[i]);
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		printf("%d\n",dp[N][V]);
	}
	return 0;
}