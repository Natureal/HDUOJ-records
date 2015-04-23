////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 21:30:43
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2052
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,m,i,j;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		printf("+");
		for(j=0;j<n;j++)
		{
			printf("-");
		}
		printf("+\n");
		for(i=0;i<m;i++)
		{
			printf("|");
			for(j=0;j<n;j++)
			{
				printf(" ");
			}
			printf("|\n");
		}
		printf("+");
		for(j=0;j<n;j++)
		{
			printf("-");
		}
		printf("+\n\n");
	}
	return 0;
}