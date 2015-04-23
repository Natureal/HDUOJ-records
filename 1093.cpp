////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-07 16:17:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1093
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,a,sum;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			sum=0;
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&a);
				sum+=a;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}