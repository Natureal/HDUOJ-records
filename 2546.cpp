////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-14 16:24:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2546
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:4212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int dp[1005][1005],price[1005];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,m,i,j,maxp,temp;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(dp,0,sizeof(dp));
		maxp=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&price[i]);
			maxp=price[i]>maxp?price[i]:maxp;
		}
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			if(maxp==price[i])
			{
				temp=price[1];
				price[1]=price[i];
				price[i]=temp;
			}
		}
		if(m>=5)
		{
			m-=5;
			for(i=2;i<=n;i++)
			{
				for(j=0;j<=m;j++)
				{
					if(j>=price[i])
						dp[i][j]=max(dp[i-1][j],dp[i-1][j-price[i]]+price[i]);
					else
						dp[i][j]=dp[i-1][j];
				}
			}
			printf("%d\n",m-dp[n][m]-maxp+5);
		}
		else
			printf("%d\n",m);
	}
	return 0;
}
	