////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-04 00:20:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1501
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:388KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{
	int n,dp[205][205];
	char s1[205],s2[205],s3[410];
	while(scanf("%d",&n)!=EOF)
	{
		for(int t = 1;t <= n;t ++)
		{
			memset(dp,0,sizeof(dp));
			scanf("%s %s %s",s1 + 1,s2 + 1,s3 + 1);
			int len1=strlen( s1 + 1 );
			int len2=strlen( s2 + 1 );
			for(int i = 1;i <= len1;i ++)
			{
				if(s1[i] == s3[i]) dp[i][0] = 1;
			}
			for(int j = 1;j <= len2;j ++)
			{
				if(s2[j] == s3[j]) dp[0][j] = 1;
			}
			for(int i = 1;i <= len1;i ++)
			{
				for(int j = 1;j <= len2;j ++)
				{
					if(s1[i] == s3[i+j] && dp[i-1][j] || s2[j] == s3[i+j] && dp[i][j-1])
					{
						dp[i][j] = 1;
					}
				}
			}
			printf("Data set %d: ",t);
			if (dp[len1][len2]==1) printf("yes\n");
			else printf("no\n");
		}
	}
}