////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-30 15:07:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1418
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	unsigned n,m;
	while(scanf("%u%u",&n,&m)!=EOF && n||m && n>0 && m>0)
	{
		printf("%u\n",n+m-2);
	}
	return 0;
}