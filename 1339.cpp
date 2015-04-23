////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-14 01:14:32
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1339
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,i;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d",&m);
			i=0;
			while(!(m%2))
			{
				m=m/2;
				i++;
			}
			printf("%d %d\n",m,i);
		}
	}
	return 0;
}