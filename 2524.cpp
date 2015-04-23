////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-01 01:00:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2524
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",m*n*(m+1)*(n+1)/4);
	}
	return 0;
}