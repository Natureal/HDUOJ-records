////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-15 00:00:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=1;
		while(--n)
		{
			sum=2*(sum+1);
		}
		printf("%d\n",sum);
	}
	return 0;
}