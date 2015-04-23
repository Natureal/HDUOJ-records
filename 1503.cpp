////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-03 21:51:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1503
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXN 10000
char s1[105],s2[105];
int dp[105][105],record[105][105];
void output(int l1,int l2)
{
	if(l1 == 0 && l2 == 0)
		return;
	if(record[l1][l2] == 1)
	{
		output(l1-1,l2);
		printf("%c",s1[l1-1]);
	}
	else if(record[l1][l2] == 2)
	{
		output(l1,l2-1);
		printf("%c",s2[l2-1]);
	}
	else if(record[l1][l2] == 3)
	{
		output(l1-1,l2-1);
		printf("%c",s1[l1-1]);
	}
	return;
}
int main()
{
	while(scanf("%s %s",s1,s2)!=EOF)
	{
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int count=0;
		memset(dp,0,sizeof(dp));
		for(int i = 1 ; i <= len1 ; i ++)
		{
			dp[i][0] = i;
			record[i][0] = 1;
		}
		for(int j = 1 ; j <= len2 ; j ++)
		{
			dp[0][j] = j;
			record[0][j] = 2;
		}
		for(int i = 1 ; i <= len1 ; i ++)
		{
			for(int j = 1 ; j <= len2 ; j ++)
			{
				if(s1[i-1] == s2[j-1])
				{
					dp[i][j] = dp[i-1][j-1]+1;
					record[i][j]=3;
				}
				else
				{
					//dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
					if(dp[i-1][j] < dp[i][j-1])
					{
						dp[i][j] = dp[i-1][j]+1;
						record[i][j] = 1;
					}
					else
					{
						dp[i][j] = dp[i][j-1]+1;
						record[i][j] = 2;
					}
				}
			}
		}
	/*	printf("%d\n",dp[len1][len2]);
		for(int i = 1;i <= len1;i ++)
		{
			for(int j = 1;j <= len2;j ++)
			{
				printf("%d",record[i][j]);
			}
			puts("");
		}*/
		output(len1,len2);
		printf("\n");
	}
	return 0;
}