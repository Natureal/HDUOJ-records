////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-04 23:20:23
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1587
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,i,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		scanf("%d",&k);
		while(--n)
		{
			scanf("%d",&i);
			k=k<i?k:i;
		}
		printf("%d\n",m/k);
	}
	return 0;
}