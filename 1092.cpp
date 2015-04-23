////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-07 00:56:44
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1092
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,sum,a;

	while(scanf("%d",&n)!=EOF)
	{
		if(0==n) return 0;
		sum=0;
		while(n--)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}
	return 0;
}