////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-02 22:49:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1257
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
using namespace std;
int dp[1005];
int main()
{
	int n,h,count,i,j;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(dp,0,sizeof(dp));
		dp[1]=100000;
		count=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&h);
			for(j=1;j<=count;j++)
			{
				if(dp[j]>h)
					break;
			}
			dp[j]=h;
			if(j>count)
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}