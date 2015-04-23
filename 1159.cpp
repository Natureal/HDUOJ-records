////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-03 00:32:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1159
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:16024KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int dp[2005][2005];
char str1[2005],str2[2005];
int main()
{
	while(scanf("%s %s",str1+1,str2+1)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		int len1=strlen(str1+1);
		int len2=strlen(str2+1);
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				if(str1[i]==str2[j])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}