////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-01 21:39:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1176
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:10436KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define MAXN 100000
int map[MAXN+5][13],dp[MAXN+5][13];
int max_int(int a,int b,int c)
{
	a=a>b?a:b;
	c=a>c?a:c;
	return c;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,x,t;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(map,0,sizeof(map));
		memset(dp,0,sizeof(dp));
		int maxt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&t);
			map[t][x+1]++;
			if(t>maxt)
				maxt=t;
		}
		int max=0;
		for(int k=5;k<=7;k++)
		{
			dp[1][k]=map[1][k];
		}
		for(int i=2;i<=maxt;i++)
		{
			for(int j=1;j<=11;j++)
			{
				dp[i][j]+=max_int(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])+map[i][j];
				if(dp[i][j]>max)
					max=dp[i][j];

			}
		}
		printf("%d\n",max);
	}
	return 0;
}