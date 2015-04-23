////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-10-29 23:49:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,j,sum;
	while(scanf("%d",&i)!=EOF)
	{
		sum=0;
		for(j=1;j<=i;j++)
		{
			sum+=j;
		}
		printf("%d\n\n",sum);
	}
	return 0;
}