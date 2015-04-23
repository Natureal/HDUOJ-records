////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-21 00:23:32
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2107
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,d,n;
	while(scanf("%d",&n)!=EOF && n)
	{
		scanf("%d",&a);
		while(--n)
		{
			scanf("%d",&d);
			a=a>d?a:d;
		}
		printf("%d\n",a);
	}
	return 0;
}